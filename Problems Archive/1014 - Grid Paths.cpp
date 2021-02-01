#include <iostream>
#include <string>
using namespace std;

string s, m = "LRUD";
int vis[7][7];
int r[4] = { 0, 0, -1, 1 };
int c[4] = { -1, 1, 0, 0 };

int count(int x, int y, int i, char prev) {
	if (i == 48) { return 1; }
	if (vis[6][0]) { return 0; }
	if (prev == 'L' && (y == 0 || vis[x][y - 1]) && x > 0 && x < 6 && !vis[x - 1][y] && !vis[x + 1][y]) { return 0; }
	if (prev == 'R' && (y == 6 || vis[x][y + 1]) && x > 0 && x < 6 && !vis[x - 1][y] && !vis[x + 1][y]) { return 0; }
	if (prev == 'U' && (x == 0 || vis[x - 1][y]) && y > 0 && y < 6 && !vis[x][y - 1] && !vis[x][y + 1]) { return 0; }
	if (prev == 'D' && (x == 6 || vis[x + 1][y]) && y > 0 && y < 6 && !vis[x][y - 1] && !vis[x][y + 1]) { return 0; }
	int res = 0;
	if (s[i] == '?') {
		for (int j = 0; j < 4; j++) {
			int X = x + r[j], Y = y + c[j];
			if (X < 0 || X > 6 || Y < 0 || Y > 6 || vis[X][Y]) { continue; }
			vis[X][Y] = 1; res += count(X, Y, i + 1, m[j]); vis[X][Y] = 0;
		}
		return res;
	}
	for (int j = 0; j < 4; j++) if (s[i] == m[j]) { x += r[j]; y += c[j]; break; }
	if (x < 0 || x > 6 || y < 0 || y > 6 || vis[x][y]) { return 0; }
	vis[x][y] = 1; res = count(x, y, i + 1, s[i]); vis[x][y] = 0;
	return res;	
}

int main() {
	cin >> s; vis[0][0] = true;
	cout << count(0, 0, 0, 0) << '\n';
	cin.ignore(2); return 0;
}