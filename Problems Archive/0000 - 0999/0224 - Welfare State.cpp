#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> res;
vector<pair<int, pair<int, int>>> queries;
vector<pair<int, int>> q2;
int n, q;

void run_sim() {
	for (int i = 0; i < q; i++) {
		int c = queries[i].first;
		if (c == 1) {
			int p = queries[i].second.first - 1;
			int x = queries[i].second.second;
			res[p] = (!q2.empty()) ? max(x, q2.back().second) : x;
		}
		else {
			if (i != q2.back().first) { continue; }
			q2.pop_back();
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; res.push_back(a);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int c; cin >> c;
		if (c == 1) {
			int p, x; cin >> p >> x;
			pair<int, int> pa(p, x);
			pair<int, pair<int, int>>pp(c, pa);
			queries.push_back(pp);
		}
		else {
			int x; cin >> x;
			pair<int, int>pa(0, x);
			pair<int, pair<int, int>>pp(c, pa);
			queries.push_back(pp);
			pair<int, int>p2(i, x);
			while (!q2.empty() && q2.back().second < x) { q2.pop_back(); }
			q2.push_back(p2);
		}
	}
	reverse(q2.begin(), q2.end());
	if (!q2.empty()) {
		for (int i = 0; i < n; i++) {
			res[i] = max(res[i], q2.back().second);
		}
	}
	run_sim();
	for (int i = 0; i < n; i++) {
		cout << res[i];
		if (i + 1 != n) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}