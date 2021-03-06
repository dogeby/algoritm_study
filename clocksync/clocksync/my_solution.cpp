//�ð� ���߱�
//�˰��� �����ذ����� 1�� p168
//����: 4 x 4���� ���� ���·� ��ġ�� 16���� �ð谡 �ִ�. �� �ð���� ��� 12�ø� ����Ű���� �ٲٰ� �ʹ�. ������ ����ġ��� ������ �� ������ �� ����ġ���� ���Դ� �� ��, ���Դ� �ټ� ���� ����Ǿ� �ִ�.
//		����ġ�� ���������� ����� �ð���� �ð��� 3�ð��� ������ �����δ�.
//�ð� �� �޸� ����: 10�� �ȿ� ����, 64MB ������ �޸� ���
//�Է�: ù �ٿ� �׽�Ʈ ���̽��� ���� C(C<=30) �� �׽�Ʈ ���̽��� �� �ٿ� 16���� ������ �־����� �� ������ 0������ 15������ �� �ð谡 ����Ű�� �ִ� �ð��� 12, 3, 6, 9�� �ϳ��� ǥ���մϴ�.
//���: ����ġ�� ������ �� �ּ� Ƚ��, �Ұ����� ��� -1
//����ġ��� �׵��� ����� �ð���� ���:{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
//��Ʈ: �� ���� ���� �״��

//�� ����
//�ð� 12�ø� 0, 9�� = 1, 6�� = 2, 3�� = 3���� �����غ���.
//����ġ 0, 1, 2, 3  4���. ����Ž���ϸ� 4^10?
//��� �Լ�, ���� ��ʴ� ��� �ð� ���� 0�϶�


//�ش� ���� ��
//PullSwitch �ʿ����. 4�� ���� ���� ���·� ���ƿ��°�
//4�� �ݺ��ε� �Ǽ��� 3����������
//���� �ð��� �ٲ��ʿ����. 3, 6, 9, 12 3�� ���
//���Ͱ� �迭���� �ʹ� ����

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define INF 9999

//�迭 ù��°�� ����ġ�� ����� �ð� ������ �־���. -> ���ͷ� ������
vector<vector<int>> g_switch = {
	vector<int>({0, 1, 2}),	vector<int>({3, 7, 9, 11}),	vector<int>({4, 10, 14, 15}), vector<int>({0, 4, 5, 6, 7}),	vector<int>({6, 7, 8, 10, 12}),	vector<int>({0, 2, 14, 15})
	, vector<int>({3, 14, 15}), vector<int>({4, 5, 7, 14, 15}), vector<int>({1, 2, 3, 4, 5}), vector<int>({3, 4, 5, 9, 13})
};

void PushSwitch(int clock[16], int nextswitch, int num) {
		for (int i = 0; i < g_switch[nextswitch].size(); i++) {
			clock[g_switch[nextswitch][i]] -= num;
			if (clock[g_switch[nextswitch][i]] < 0)
				clock[g_switch[nextswitch][i]] += 4;
		}
}
void PullSwitch(int clock[16], int nextswitch, int num) {
	for (int i = 0; i < g_switch[nextswitch].size(); i++) {
		clock[g_switch[nextswitch][i]] += num;
		if (clock[g_switch[nextswitch][i]] > 3)
			clock[g_switch[nextswitch][i]] -= 4;
	}
}

int SyncClock(int clock[16], int nextswitch, int pushbtn) {
	int sum = 0, ret = INF;
	for (int i = 0; i < 16; i++)
		sum += clock[i];
	if (sum == 0)
		return pushbtn;
	if (nextswitch > 9)
		return ret;

	for (int i = 0; i < 4; i++) {
		PushSwitch(clock, nextswitch, i);
		ret = min(ret, SyncClock(clock, nextswitch + 1, pushbtn+i));
		PullSwitch(clock, nextswitch, i);
	}
	return ret;
}

void main() {
	int casenumber = 0;
	clock_t start, end;
	start = clock();
	scanf_s("%d", &casenumber);
	for (int i = 0; i < casenumber; i++) {
		int clock[16] = { 0 };
		for (int j = 0; j < 16; j++) {
			int input = 0;
			scanf_s("%d", &input);
			switch (input) {
			case 12:
				clock[j] = 0;
				break;
			case 9:
				clock[j] = 1;
				break;
			case 6:
				clock[j] = 2;
				break;
			case 3:
				clock[j] = 3;
				break;
			}
		}
		int result = SyncClock(clock, 0, 0);
		if (result >= INF)
			result = -1;
		printf_s("%d\n",result);
	}
	end = clock();
	printf_s("�ҿ�ð�: %d\n", (end - start) / CLOCKS_PER_SEC);
}