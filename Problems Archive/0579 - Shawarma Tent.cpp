#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int sx, sy;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int check(int x, int y) {
	int res = 0;
	for (auto &e : v)
		res += dist(e.first, e.second, x, y) < dist(e.first, e.second, sx, sy);
	return res;
}

int main() {
	int n; cin >> n >> sx >> sy; v.resize(n);
	for (auto &x : v) { cin >> x.first >> x.second; }
	int a[4];
	a[0] = check(sx - 1, sy); a[1] = check(sx, sy - 1);
	a[2] = check(sx, sy + 1); a[3] = check(sx + 1, sy);
	int m = *max_element(a, a + 4); cout << m << endl;
	if (m == a[0]) { cout << sx - 1 << ' ' << sy << endl; }
	else if (m == a[1]) { cout << sx << ' ' << sy - 1 << endl; }
	else if (m == a[2]) { cout << sx << ' ' << sy + 1 << endl; }
	else { cout << sx + 1 << ' ' << sy << endl; }
	cin.ignore(2); return 0;
}