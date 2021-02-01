#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct grass {
	int init, grow;

	grass() {}
	grass(int _init) :
		init(_init), grow(0) {}

	bool operator < (const grass & rhs) const {
		return grow < rhs.grow;
	}
};

int DP[51][51];
int H, k;
vector<grass> g;

int min_height(int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }
	if (g.size() - i < j) { return H + 1; }
	if (i == g.size()) { return 0; }

	int a = g[i].init + k * g[i].grow + min_height(i + 1, j);
	if (j == 0) { DP[i][j] = a; return a; }
	int b = (k - j) * g[i].grow + min_height(i + 1, j - 1);
	int min = (a < b) ? a : b;
	DP[i][j] = min; return min;
}

int cutting_grass() {
	k = 0; sort(g.rbegin(), g.rend());
	while (k <= g.size()) {
		for (unsigned int i = 0; i < g.size() + 1; i++) {
			for (int j = 0; j < k + 1; j++) { DP[i][j] = -1; }
		}
		int h = min_height(0, k);
		if (h <= H) { return k; }
		k++;
	}
	return -1;
}

int main() {
	char c;
	cin >> c;
	while (c != '}') {
		int a; cin >> a >> c;
		grass gr(a); g.push_back(gr);
	}
	cin >> c >> c; int i = 0;
	while (c != '}') { 
		int a; cin >> a >> c;
		g[i].grow = a; i++;
	}
	cin >> c >> H;
	cout << cutting_grass() << endl;
	cin.ignore(2); return 0;
}