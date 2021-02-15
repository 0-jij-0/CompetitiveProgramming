#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>
using namespace std;

vector<int> a[4];
vector<int> v[4];
set<pair<int, int>> s[4];

struct pqObj {
	vector<int> idx; pqObj() {}
	pqObj(int a, int b, int c, int d) :
		idx({ a, b, c, d }) {}
	
	bool operator < (const pqObj& rhs)const {
		int x = 0, y = 0;
		for (int i = 0; i < 4; i++) {
			x += a[i][v[i][idx[i]]];
			y += a[i][v[i][rhs.idx[i]]];
		}
		return x > y;
	}
};

priority_queue<pqObj> pq;

int check(vector<int> &idx) {
	int ind[4]; for (int i = 0; i < 4; i++)
		ind[i] = v[i][idx[i]];

	for(int i = 0; i < 3; i++)
		if (s[i].count({ ind[i], ind[i + 1] })) { return 0; }

	int s = 0; for (int i = 0; i < 4; i++)
		s += a[i][ind[i]];

	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n[4]; cin >> n[0] >> n[1] >> n[2] >> n[3];
	for (int i = 0; i < 4; i++) {
		a[i].resize(n[i]); v[i].resize(n[i]);
		iota(v[i].begin(), v[i].end(), 0);
		for (auto& x : a[i]) cin >> x;
		auto comp = [&](const int& j, const int& k) {
			return a[i][j] < a[i][k];
		}; sort(v[i].begin(), v[i].end(), comp);
	}

	int m[3]; for (int i = 0; i < 3; i++) {
		cin >> m[i]; while (m[i]--) {
			int x, y; cin >> x >> y;
			s[i].insert({ --x, --y });
		}
	}

	pq.push(pqObj(0, 0, 0, 0)); int res = -1;
	while (!pq.empty()) {
		pqObj cur = pq.top(); pq.pop();
		int x = check(cur.idx);
		if (x) { res = x; break; }

		vector<int>& idx = cur.idx;
		for (int i = 0; i < 3; i++) {
			if (s[i].count({ v[i][idx[i]], v[i + 1][idx[i + 1]] })) {
				if (idx[i] + 1 != v[i].size()) {
					idx[i]++; pq.push(pqObj(idx[0], idx[1], idx[2], idx[3])); idx[i]--;
				}
				if (idx[i + 1] + 1 != v[i + 1].size()) {
					idx[i + 1]++; pq.push(pqObj(idx[0], idx[1], idx[2], idx[3])); idx[i + 1]--;
				}
				break;
			}
		}
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}