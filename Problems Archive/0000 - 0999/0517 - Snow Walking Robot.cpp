#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<char, int> m = { {'U', 0}, {'D', 1}, {'L', 2}, {'R', 3} };
char mo[4] = { 'U', 'D', 'L', 'R' };

int main() {
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		vector<int> moves(4, 0);
		for (char &c : s) { moves[m[c]]++; }
		int v = min(moves[0], moves[1]);
		int h = min(moves[2], moves[3]);
		moves[0] = moves[1] = v;
		moves[2] = moves[3] = h;
		if (!moves[0]) { moves[2] = moves[3] = min(moves[2], 1); }
		if (!moves[2]) { moves[0] = moves[1] = min(moves[0], 1); }
		int res = moves[0] + moves[1] + moves[2] + moves[3];
		cout << res << endl;
		while (moves[0]--) { cout << mo[0]; }
		while (moves[2]--) { cout << mo[2]; }
		while (moves[1]--) { cout << mo[1]; }
		while (moves[3]--) { cout << mo[3]; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}
