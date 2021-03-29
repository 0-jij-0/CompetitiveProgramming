#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

int main() {
	int h, w, x, y; cin >> h >> w >> x >> y;
	x--; y--; v.resize(h); for (auto& x : v) cin >> x;

	int res = 1, i = x - 1, j = y - 1;
	while (i != -1 && v[i][y] != '#') { res++; i--; }
	i = x + 1; while (i != h && v[i][y] != '#') { res++; i++; }
	while (j != -1 && v[x][j] != '#') { res++; j--; }
	j = y + 1; while (j != w && v[x][j] != '#') { res++; j++; }
	cout << res << '\n';

	cin.ignore(2); return 0;
}