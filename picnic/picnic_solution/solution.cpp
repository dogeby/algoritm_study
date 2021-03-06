//p158	책 해답과 조금 다름. 메인이 없었는데 아마 areFriends에 저장할때 3 0 이면 [0][3]에 저장한듯? 
#include <stdio.h>
using namespace std;

int n;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		//if (!taken[pairWith] && areFriends[firstFree][pairWith]) {	areFriends[pairWith][firstFree]면 인식 못함
		if (!taken[pairWith] && (areFriends[firstFree][pairWith]||areFriends[pairWith][firstFree])){	//해결책1
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

void main() {
	int caseNum = 0, friendNum = 0, pair = 0;
	scanf_s("%d", &caseNum);
	for (int c = 0; c < caseNum; c++) {
		//areFriends[10][10] = { false };	//선언 후 초기화는 이렇게하면 ㄴㄴ
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				areFriends[i][j] = false;
		scanf_s("%d %d", &n, &pair);
		int i = 0, j = 0; //친구 쌍 (i, j)
		for (int m = 0; m < pair; m++) {
			scanf_s("%d %d", &i, &j);
			areFriends[i][j] = true;
		}
		bool taken[10] = { false };
		printf("%d\n", countPairings(taken));
	}
}