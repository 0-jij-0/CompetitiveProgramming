#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v; int n;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

string getStr(int k, int i, int j) {
	string s = "";
	for (int x = 0; x < n; x++) {
		s.push_back(v[i][j]);
		i = (i + dx[k] + n) % n;
		j = (j + dy[k] + n) % n;
	}
	return move(s);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; v.resize(n);
	for (auto& x : v) cin >> x;

	string res(n, '0');
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 8; k++)
				res = max(res, getStr(k, i, j));

	cout << res << '\n';
}