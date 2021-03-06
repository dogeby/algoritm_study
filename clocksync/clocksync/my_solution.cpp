//시계 맞추기
//알고리즘 문제해결전략 1권 p168
//문제: 4 x 4개의 격자 형태로 배치된 16개의 시계가 있다. 이 시계들을 모두 12시를 가리키도록 바꾸고 싶다. 열개의 스위치들로 조작할 수 있으며 각 스위치들은 적게는 세 개, 많게는 다섯 개에 연결되어 있다.
//		스위치를 누를때마다 연결된 시계들의 시간이 3시간씩 앞으로 움직인다.
//시간 및 메모리 제한: 10초 안에 실행, 64MB 이하의 메모리 사용
//입력: 첫 줄에 테스트 케이스의 개수 C(C<=30) 각 테스트 케이스는 한 줄에 16개의 정수로 주어지며 각 정수는 0번부터 15번까지 각 시계가 가리키고 있는 시간을 12, 3, 6, 9중 하나로 표현합니다.
//출력: 스위치를 눌러야 할 최소 횟수, 불가능할 경우 -1
//스위치들과 그들이 연결된 시계들의 목록:{0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
//힌트: 한 바퀴 돌면 그대로

//내 생각
//시계 12시를 0, 9시 = 1, 6시 = 2, 3시 = 3으로 생각해보자.
//스위치 0, 1, 2, 3  4경우. 완전탐색하면 4^10?
//재귀 함수, 기저 사례는 모든 시계 합이 0일때


//해답 보고난 후
//PullSwitch 필요없음. 4번 돌면 이전 상태로 돌아오는것
//4번 반복인데 실수로 3번으로했음
//굳이 시간을 바꿀필요없음. 3, 6, 9, 12 3의 배수
//백터가 배열보다 너무 느림

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define INF 9999

//배열 첫번째에 스위치와 연결된 시계 갯수를 넣었다. -> 벡터로 만들자
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
	printf_s("소요시간: %d\n", (end - start) / CLOCKS_PER_SEC);
}