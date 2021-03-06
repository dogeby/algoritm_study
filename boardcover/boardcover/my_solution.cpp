//게임판 덮기(ID: BOARDCOVER)
//알고리즘 문제해결 전략 p159 
//문제: H * W 크기의 게임판이 있습니다. 모든 흰칸을 세 칸짜리 L자 모양의 블록으로 덮고 싶습니다. 게임판이 주어질 때 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.
//시간 및 메모리 제한: 2초안에 실행, 64MB 이하의 메모리 사용
//입력: 첫 줄에는 테스트 케이스의 수 C(C<=30), 각 테스트 케이스의 첫 줄에는 두 개의 정수 H, W(1<= H, W<=20)가 주어집니다. H 줄에 각 W글자로 게임판 모양이 주어집니다.
//		#은 검은 칸, .는 흰 칸을 나타냅니다. 흰 칸의 수는 50을 넘지 않습니다.
//출력: 한 줄에 하나씩 흰 칸을 모두 덮는 방법의 수를 출력

//내 생각: 왼쪽 위에서부터 무작정 채워 넣어보자, 일단 흰색이 3의 배수가 아니면 다 못넣는거같다. L 중심을 흰색에 하고 4번 돌려보자.

//너무 느림. 마지막 인풋 결과 안나옴. 마지막 인풋은 어디서 무한루프인듯함.  특정한 순서대로 답이 나오도록해야함 -> 왼쪽, 위는 채운다 생각으로 해야함. 그러면 3시, 5시, 6시, 7시만 신경쓰기 가능

#include <stdio.h>

int g_whiteCount;

int coverWhite(bool board[20][20], int height, int width, int h, int w);
bool set(bool board[20][20], int y, int x, int height, int width, int type);

void main() {
	int testCaseNumber = 0, height = 0, width = 0;
	char inputChar = '\0';

	scanf_s("%d", &testCaseNumber);
	for (int i = 0; i < testCaseNumber; i++) {
		scanf_s("%d %d", &height, &width);
		bool board[20][20] = { false };
		g_whiteCount = 0;
		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				scanf_s(" %c", &inputChar, 1);
				if (inputChar == '.') {
					board[h][w] = true;
					g_whiteCount++;
				}
			}
		}
		if ((g_whiteCount % 3) == 0) {
			int result = coverWhite(board, height, width, 0, 0);
			printf_s("%d\n", result);
		}
		else
			printf_s("0\n");
	}
}

const int coverType[4][3][2] = {
	{{0,0}, {1,0}, {0,1}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
};

//int coverWhite(bool board[20][20], int height, int width, int h, int w) {
//	if (g_whiteCount == 0)
//		return 1;
//	int result = 0;
//	for (; h < height; h++) {
//		for (; w < width; w++) {
//			if (board[h][w]) {
//				if (h - 1 >= 0 && board[h - 1][w]) {	//ㄴ 세로,ㄴ 대칭일때
//					if (w - 1 >= 0 && board[h][w-1]) {
//						board[h][w] = false;
//						board[h - 1][w] = false;
//						board[h][w - 1] = false;
//						g_whiteCount-=3;
//						result += coverWhite(board, height, width, h, w+1);
//						board[h][w] = true;
//						board[h - 1][w] = true;
//						board[h][w - 1] = true;
//						g_whiteCount+=3;
//					}
//					if (w + 1 < width && board[h][w + 1]) {
//						board[h][w] = false;
//						board[h - 1][w] = false;
//						board[h][w + 1] = false;
//						g_whiteCount-=3;
//						result += coverWhite(board, height, width, h, w + 1);
//						board[h][w] = true;
//						board[h - 1][w] = true;
//						board[h][w + 1] = true;
//						g_whiteCount+=3;
//					}
//				}
//				else if (h + 1 < height && board[h + 1][w]) {	//ㄱ, ㄱ 세로 대칭일때
//					if (w - 1 >= 0 && board[h][w - 1]) {
//						board[h][w] = false;
//						board[h + 1][w] = false;
//						board[h][w - 1] = false;
//						g_whiteCount-=3;
//						result += coverWhite(board, height, width, h, w + 1);
//						board[h][w] = true;
//						board[h + 1][w] = true;
//						board[h][w - 1] = true;
//						g_whiteCount+=3;
//					}
//					if (w + 1 < width && board[h][w + 1]) {
//						board[h][w] = false;
//						board[h + 1][w] = false;
//						board[h][w + 1] = false;
//						g_whiteCount-=3;
//						result += coverWhite(board, height, width, h, w + 1);
//						board[h][w] = true;
//						board[h + 1][w] = true;
//						board[h][w + 1] = true;
//						g_whiteCount+=3;
//					}
//				}
//			}
//		}
//		w = 0;
//	}
//	return result;
//}
