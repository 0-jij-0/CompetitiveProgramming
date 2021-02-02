#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int t; cin >> t;
	cout << t << '\n';
 
	while (t--) {
		string path; cin >> path;
 
		for (int s = 1; s < 99; s++) {
			vector<vector<char>> ans(100, vector<char>(100, '#'));
			ans[s][0] = '.';
			int state = 0;	//0:R, 1:L, 2:T, 3:D
			int i = s, j = 0;
			bool OK = true;
 
			for (auto &c : path) {
				int ni = i, nj = j;
				if (c == 'F') {
					if (state == 0) { nj++; }
					else if (state == 1) { nj--; }
					else if (state == 2) { ni--; }
					else { ni++; }
				}
				else if (c == 'L') {
					if (state == 0) { ni--; state = 2; }
					else if (state == 1) { ni++; state = 3; }
					else if (state == 2) { nj--; state = 1; }
					else { nj++; state = 0; }
				}
				else if (c == 'R') {
					if (state == 0) { ni++; state = 3; }
					else if (state == 1) { ni--; state = 2; }
					else if (state == 2) { nj++; state = 0; }
					else { nj--; state = 1; }
				}
				else {
					if (state == 0) { nj--; state = 1; }
					else if (state == 1) { nj++; state = 0; }
					else if (state == 2) { ni++; state = 3; }
					else { ni--; state = 2; }
				}
				if (ni == 99 || nj == 99 || ni == 0) { OK = false; break; }
				if (nj == 0 && ni != s) { OK = false; break; }
 
				i = ni; j = nj;
				ans[i][j] = '.';
			}
			if (i != s || j != 0) { OK = false; }
			if (!OK) { continue; }
 
			int maxRow = 100, maxCol = 100;
			for (int a = 1; a < 99; a++) {
				bool found = false;
				for (int b = 1; b < 99; b++) {
					if (ans[a][b] == '.') { found = true; break; }
				}
				if (!found) { maxRow = a + 1; break; }
			}
			for (int a = 1; a < 99; a++) {
				bool found = false;
				for (int b = 1; b < 99; b++) {
					if (ans[b][a] == '.') { found = true; break; }
				}
				if (!found) { maxCol = a + 1; break; }
			}
 
			cout << maxRow << ' ' << maxCol << '\n';
			for (int a = 0; a < maxRow; a++) {
				for (int b = 0; b < maxCol; b++) {
					cout << ans[a][b];
				}
				cout << '\n';
			}
			break;
		}
	}
}