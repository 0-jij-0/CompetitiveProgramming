#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

string s, t = "abc";
vector<int> dist[6];

void fill(int id) {
	for (int i = 0; i < (int)s.size(); i++)
		dist[id][i] = (s[i] != t[i % 3]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m >> s; int id = 0;
	for (int i = 0; i < 6; i++) dist[i].resize(n);
	do { fill(id++); } while (next_permutation(t.begin(), t.end()));

	for (int i = 0; i < 6; i++)
		partial_sum(dist[i].begin(), dist[i].end(), dist[i].begin());

	while (m--) {
		int l, r; cin >> l >> r; l--; r--;
		int res = n; for (int i = 0; i < 6; i++)
			res = min(res, l ? dist[i][r] - dist[i][l - 1] : dist[i][r]);
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}