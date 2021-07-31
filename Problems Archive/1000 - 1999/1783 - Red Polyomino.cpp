#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<string> v; int n;

struct setCompare {
	bool operator()(const set<int> &s1, const set<int> &s2) const {
		auto it1 = s1.begin(), it2 = s2.begin();
		while (it1 != s1.end() && it2 != s2.end()) {
			if (*it1 != *it2) { return *it1 < *it2; }
			it1++; it2++;
		}
		return it2 != s2.end();
	}
};

set<set<int>, setCompare> dp; int res = 0;

void count(vector<string>& v, set<int> &cur, set<int> st, int i, int j, int k) {
	if (dp.count(cur)) { return; }
	dp.insert(cur); if (k == 0) { res++; return; }
	if (i && v[i - 1][j] == '.') st.insert((i - 1) * n + j);
	if (j && v[i][j - 1] == '.') st.insert(i * n + j - 1);
	if (i != n - 1 && v[i + 1][j] == '.') st.insert((i + 1) * n + j);
	if (j != n - 1 && v[i][j + 1] == '.') st.insert(i * n + j + 1);

	set<int> stt = st;
	for (auto& x : st) if(!cur.count(x)) {
		cur.insert(x); stt.erase(x);
		count(v, cur, stt, x / n, x % n, k - 1);
		cur.erase(x); stt.insert(x);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k; cin >> n >> k; v.resize(n);
	for (auto& x : v) { cin >> x; }
	set<int> cur, st;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (v[i][j] == '#') { continue; }
			v[i][j] = '#'; cur.insert(i * n + j);
			count(v, cur, st, i, j, k - 1);
			cur.erase(i * n + j);
		}

	cout << res << '\n';
	cin.ignore(2); return 0;
}