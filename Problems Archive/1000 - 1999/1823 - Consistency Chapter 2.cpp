#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int minCost[26][26];

void computeMinCost() {
	for (int k = 0; k < 26; k++) 
		for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) 
			minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
}

int tryLetter(const string& s, const char c) {
	int res = 0; for (auto& x : s) if (x != c)
		if (minCost[x - 'A'][c - 'A'] > 100) return 1 << 30;
		else res += minCost[x - 'A'][c - 'A'];
	return res;
}

int main() {
	ifstream cin("A2.in.txt");
	ofstream cout("A2.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		fill(minCost[0], minCost[0] + 26 * 26, 1000);
		string s; int k; cin >> s >> k; 

		for (int i = 0; i < k; i++) {
			char u, v; cin >> u >> v;
			minCost[u - 'A'][v - 'A'] = 1;
		}

		computeMinCost(); int res = 1 << 30;
		for (char c = 'A'; c <= 'Z'; c++)
			res = min(res, tryLetter(s, c));

		cout << "Case #" << t << ": ";
		cout << (res < (1 << 30) ? res : -1) << '\n';
	}
	return 0;
}