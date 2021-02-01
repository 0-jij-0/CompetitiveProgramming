#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

struct Tree {
	int p, h = 0, idx, l, r; Tree() {}
	Tree(int _p, int _h, int _i, int _l, int _r) :
		p(_p), h(_h), idx(_i), l(_l), r(_r) {}
};

int main() {
	ofstream ofs("out.txt");
	ifstream ifs("in.txt");

	int T; ifs >> T;
	for (int t = 1; t <= T; t++) {
		int n; ifs >> n; map<int, int> comp;
		vector<Tree> v(n);
		for (int i = 0; i < n; i++) {
			int p, h; ifs >> p >> h;
			v[i] = Tree(p, h, p, p - h, p + h);
			comp[p]; comp[p - h]; comp[p + h];
		}
		int id = 0; for (auto &x : comp) { x.second = id++; }
		vector<Tree> trees(id); for (auto &x : v) {
			x.idx = comp[x.idx]; x.l = comp[x.l];
			x.r = comp[x.r]; trees[x.idx] = x;
		}
		ll res = 0; vector<ll> dp(id, 0);
		for (int i = 1; i < id; i++) {
			if (!trees[i].h) { res = max(res, dp[i]); continue; }
			dp[trees[i].r] = max(dp[trees[i].r], dp[i] + trees[i].h);
			dp[i] = max(dp[i], trees[i].h + dp[trees[i].l]);
			res = max(res, dp[i]);
		}
		ofs << "Case #" << t << ": " << res << '\n';
	}
	cin.ignore(2); return 0;
}