#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>
#include <fstream>
using namespace std;

vector<pair<int, int>> v;
vector<int> res, idx, cur, par;

int main() {
	ifstream ifs("people.in");
	ofstream ofs("people.out");
	int n; ifs >> n; v.resize(n); res.resize(n + 1, 1 << 30);
	for (auto &x : v) { ifs >> x.first >> x.second; }
	idx.resize(n); iota(idx.begin(), idx.end(), 0);
	auto comp1 = [&](const int &x, const int &y) { 
		if (v[x].first != v[y].first) { return v[x].first < v[y].first; }
		return v[x].second > v[y].second;
	};
	sort(idx.begin(), idx.end(), comp1); res.resize(n + 1, 1 << 30); res[0] = -res[0];

	par.resize(n, -1); cur.resize(n + 1, -1);
	for (int i = 0; i < n; i++) {
		auto it = --upper_bound(res.begin(), res.end(), v[idx[i]].second); int id = it - res.begin();
		if (cur[id] != -1 && (v[cur[id]].first == v[idx[i]].first || v[cur[id]].second == v[idx[i]].second)) { continue; }
		par[idx[i]] = cur[id]; cur[id + 1] = idx[i]; *(++it) = v[idx[i]].second;
	}

	int len = find(res.begin(), res.end(), 1 << 30) - res.begin() - 1;
	ofs << len << '\n'; int x = cur[len]; stack<int> st;
	while (x != -1) { st.push(x); x = par[x]; }
	while (!st.empty()) { ofs << st.top() + 1 << ' '; st.pop(); }
	ofs << '\n'; return 0;
}