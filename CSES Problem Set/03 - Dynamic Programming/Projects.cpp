#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Project {
	int s, e, r; Project() {}
	Project(int _s, int _e, int _r) : s(_s), e(_e), r(_r) {}
	bool operator < (const Project &rhs) const { return e < rhs.e; }
};

vector<int> comp;
vector<Project> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) {
		int s, e, r; cin >> s >> e >> r;
		comp.push_back(s); comp.push_back(e);
		v[i] = Project(s, e, r);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for (auto &x : v) { 
		x.s = lower_bound(comp.begin(), comp.end(), x.s) - comp.begin() + 1;
		x.e = lower_bound(comp.begin(), comp.end(), x.e) - comp.begin() + 1;
	}
	sort(v.begin(), v.end()); vector<ll> dp(comp.size() + 1, 0); int j = 0;

	for (int i = 1; i <= (int)comp.size(); i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		while (j < n && v[j].e == i) {
			dp[i] = max(dp[i], dp[v[j].s - 1] + v[j].r); j++;
		}
	}
	cout << dp.back() << '\n';
}