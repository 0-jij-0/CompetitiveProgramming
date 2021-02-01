#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> v;
int n, m;

pair<int, int> check(int k) {
	map<int, int> s;
	for (int i = 0; i < n; i++) {
		int mask = 0;
		for (int j = 0; j < m; j++)
			if (v[i][j] >= k) 
				mask |= 1 << j;
		s[mask] = i;
	}
	vector<pair<int, int>> p;
	for (auto &x : s)
		p.push_back(x);

	if (p.back().first == (1 << m) - 1)
		return { p.back().second, p.back().second };

	int l = (int)p.size();
	for (int i = 0; i < l; i++)
		for (int j = i + 1; j < l; j++)
			if ((p[i].first | p[j].first) == ((1 << m) - 1))
				return { p[i].second, p[j].second };
	return { -1, -1 };
}

int find_minimax() {
	int l = 0, r = 1000 * 1000 * 1000;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		pair<int, int> p = check(mid);
		p.first >= 0 ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (auto &x : v)
		for (auto &y : x)
			cin >> y;

	int x = find_minimax();
	pair<int, int> p = check(x);
	cout << p.first + 1 << ' ' << p.second + 1 << endl;
	cin.ignore(2); return 0;
}