#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree;
vector<int> pruferCode;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; pruferCode.resize(n - 2);
	vector<int> valCount(n + 1); set<int> freeNodes;
	for (auto& x : pruferCode) { cin >> x; valCount[x]++; }

	for (int i = 1; i <= n; i++)
		if (!valCount[i]) freeNodes.insert(i);

	for (auto& x : pruferCode) {
		tree.emplace_back(*freeNodes.begin(), x);
		freeNodes.erase(freeNodes.begin());
		if (--valCount[x] == 0) freeNodes.insert(x);
	}

	tree.emplace_back(*freeNodes.begin(), *freeNodes.rbegin());
	for (auto& x : tree) cout << x.first << ' ' << x.second << '\n';
}