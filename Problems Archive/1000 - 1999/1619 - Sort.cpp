#include <iostream>
#include <vector>
using namespace std;

vector<int> bits[31]; int n;
vector<int> idx(31, 0), vis, v, res;
int pNext = 0;

void sort(int cur) {
	vis[cur] = 1; res.push_back(v[cur]); int nextCur = 1 << 30;
	for (int i = 0; i < 30; i++) if (v[cur] & (1 << i)) {
		while (idx[i] != (int)bits[i].size() && vis[bits[i][idx[i]]]) idx[i]++;
		if (idx[i] != (int)bits[i].size()) { nextCur = min(nextCur, bits[i][idx[i]]); }
	}
	if (nextCur == 1 << 30) {
		while (pNext != n && vis[pNext]) { pNext++; }
		if (pNext != n) return sort(pNext);
	}
	else { return sort(nextCur); }
}

int main() {
	freopen("sorting.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; v.resize(n); vis.resize(n);
	for (auto& x : v) { cin >> x; }
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 30; j++)
			if (v[i] & (1 << j)) bits[j].push_back(i);

	sort(0); for (auto& x : res) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}