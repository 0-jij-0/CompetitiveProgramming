#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A; int n;

int doesEnd(int i, const bool p, vector<int>& ends, vector<int> &vis, vector<int> &mainLink) {
	vis[i] = p; if (!p) mainLink[i] = i; 
	if (i + A[i] < 0 || i + A[i] >= n) return ends[i] = 1;
	if (vis[i + A[i]] != -1) {
		if (p) mainLink[i] = mainLink[i + A[i]];
		return ends[i] = ends[i + A[i]];
	}
	int res = doesEnd(i + A[i], p, ends, vis, mainLink);
	if (p) mainLink[i] = mainLink[i + A[i]];
	return ends[i] = res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		cin >> n; A.resize(n); ll res = 0;
		for (auto& x : A) cin >> x;
		vector<int> vis(n, -1), ends(n, 0), mainLink(n, -1);

		doesEnd(0, 0, ends, vis, mainLink);
		for (int i = 0; i < n; i++) if (vis[i] == -1) 
			doesEnd(i, 1, ends, vis, mainLink);

		vector<int> mainLinkFreq(n, 0);
		for (int i = 0; i < n; i++) 
			if (mainLink[i] != -1)
				mainLinkFreq[mainLink[i]]++;

		if (ends[0]) for (int i = 0; i < n; i++)
			if (vis[i]) res += (n << 1 | 1);

		int endCount = count(ends.begin(), ends.end(), 1); vis.assign(n, 0);
		for (int cur = 0; cur >= 0 && cur < n && !vis[cur]; cur += A[cur]) {
			vis[cur] = 1; res += n + 1 + endCount;
			if (ends[cur]) { res -= mainLinkFreq[cur]; endCount -= mainLinkFreq[cur]; }
		}

		cout << res << '\n';		
	}
}