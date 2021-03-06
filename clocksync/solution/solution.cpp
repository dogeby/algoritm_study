//p171

#include <stdio.h>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x..",
};

bool areAligned(const vector<int>& clocks) {
	for (int i = 0; i < clocks.size(); i++)
		if (clocks[i] != 12)
			return false;
	return true;
}

void push(vector<int>&clocks, int swtch) {
	for(int clock = 0; clock < CLOCKS; ++clock)
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
}

int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}

void main() {
	int casenumber = 0;
	clock_t start, end;
	scanf_s("%d", &casenumber);
	start = clock();
	for (int i = 0; i < casenumber; i++) {
		vector<int> clocks[16];
		for (int j = 0; j < 16; j++) {
			int input = 0;
			scanf_s("%d", &input);
			clocks->push_back(input);
		}
		int result = solve(*clocks, 0);
		if (result >= INF)
			result = -1;
		printf_s("%d\n", result);
	}
	end = clock();
	printf_s("소요시간: %d\n", (end - start) / CLOCKS_PER_SEC);
}