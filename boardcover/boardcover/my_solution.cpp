//������ ����(ID: BOARDCOVER)
//�˰��� �����ذ� ���� p159 
//����: H * W ũ���� �������� �ֽ��ϴ�. ��� ��ĭ�� �� ĭ¥�� L�� ����� ������� ���� �ͽ��ϴ�. �������� �־��� �� �̸� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
//�ð� �� �޸� ����: 2�ʾȿ� ����, 64MB ������ �޸� ���
//�Է�: ù �ٿ��� �׽�Ʈ ���̽��� �� C(C<=30), �� �׽�Ʈ ���̽��� ù �ٿ��� �� ���� ���� H, W(1<= H, W<=20)�� �־����ϴ�. H �ٿ� �� W���ڷ� ������ ����� �־����ϴ�.
//		#�� ���� ĭ, .�� �� ĭ�� ��Ÿ���ϴ�. �� ĭ�� ���� 50�� ���� �ʽ��ϴ�.
//���: �� �ٿ� �ϳ��� �� ĭ�� ��� ���� ����� ���� ���

//�� ����: ���� ���������� ������ ä�� �־��, �ϴ� ����� 3�� ����� �ƴϸ� �� ���ִ°Ű���. L �߽��� ����� �ϰ� 4�� ��������.

//�ʹ� ����. ������ ��ǲ ��� �ȳ���. ������ ��ǲ�� ��� ���ѷ����ε���.  Ư���� ������� ���� ���������ؾ��� -> ����, ���� ä��� �������� �ؾ���. �׷��� 3��, 5��, 6��, 7�ø� �Ű澲�� ����

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
//				if (h - 1 >= 0 && board[h - 1][w]) {	//�� ����,�� ��Ī�϶�
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
//				else if (h + 1 < height && board[h + 1][w]) {	//��, �� ���� ��Ī�϶�
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
