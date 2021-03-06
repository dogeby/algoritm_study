//소풍(ID: PICNIC)
//알고리즘 문제해결 전략 p155 
//문제: 각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝 지을 수 있는 방법의 수를 계산하는 프로그램을 작성하세요.
//입력: 첫 줄에는 테스트 케잉스의 수 C(C<=50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 n(2<=n<=10)과 친구 쌍의 수 m(0<=m<=n(n-1)/2)이 주어집니다.
//		그 다음 줄에 m개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다. 번호는 모두 0부터 n-1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다. 학생들의 수는 짝수 입니다.

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
		int i = 0, j = 0; //친구 쌍 (i, j)
		for (int m = 0; m < pair; m++) {
			scanf_s("%d %d", &i, &j);
			g_relationship[i][j] = 1;
		}
	}
}

//너무 어렵게 생각했음. 문제에 없는 조건 스스로 만들지 말기.