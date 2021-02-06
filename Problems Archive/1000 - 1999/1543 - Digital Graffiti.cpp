#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v; int h, w;

int dx[4] = { 0, 0, 1, 1 };
int dy[4] = { 0, 1, 0, 1 };

bool check(int i, int j) {
	int res = 0;
	for (int k = 0; k < 4; k++)
		res += v[i + dx[k]][j + dy[k]] == '#';
	return res & 1;
}

int main() {
	cin >> h >> w; v.resize(h);
	for (auto& x : v) { cin >> x; }

	int res = 0;
	for (int i = 0; i < h - 1; i++)
		for (int j = 0; j < w - 1; j++)
			res += check(i, j);

	cout << res << '\n';
	cin.ignore(2); return 0;
}