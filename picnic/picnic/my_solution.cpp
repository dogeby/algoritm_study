//��ǳ(ID: PICNIC)
//�˰��� �����ذ� ���� p155 
//����: �� �л����� �ֿ� ���� �̵��� ���� ģ������ ���ΰ� �־��� ��, �л����� ¦ ���� �� �ִ� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
//�Է�: ù �ٿ��� �׽�Ʈ ���׽��� �� C(C<=50)�� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� n(2<=n<=10)�� ģ�� ���� �� m(0<=m<=n(n-1)/2)�� �־����ϴ�.
//		�� ���� �ٿ� m���� ���� ������ ���� ģ���� �� �л��� ��ȣ�� �־����ϴ�. ��ȣ�� ��� 0���� n-1 ������ �����̰�, ���� ���� �Է¿� �� �� �־����� �ʽ��ϴ�. �л����� ���� ¦�� �Դϴ�.

#include <stdio.h>

using namespace std;

int matching(bool isMatching[]);
int g_relationship[10][10];

void main() {
	int caseNum = 0, friendNum = 0, pair = 0;

	scanf_s("%d", &caseNum);
	for (int c = 0; c < caseNum; c++) {
		g_relationship[10][10] = { 0 };
		bool isMatching[10] = { false };
		scanf_s("%d %d", &friendNum, &pair);
		int i = 0, j = 0; //ģ�� �� (i, j)
		for (int m = 0; m < pair; m++) {
			scanf_s("%d %d", &i, &j);
			g_relationship[i][j] = 1;
		}
	}
}

//�ʹ� ��ư� ��������. ������ ���� ���� ������ ������ ����.