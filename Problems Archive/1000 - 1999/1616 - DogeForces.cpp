#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> res;
vector<pair<int, int>> edges;
vector<vector<int>> v;
int n, k;

int buildTree(set<int> idx, int rootSalary) {
	if (idx.size() == 1) { return *idx.begin(); }
	int curRoot = k++; res.push_back(rootSalary);

	while (!idx.empty()) {
		int cur = *idx.begin(), nextRootSalary = 0;
		set<int> newIDX; newIDX.insert(cur);

		for (auto& x : idx) if(cur != x && v[cur][x] < rootSalary) {
			nextRootSalary = max(nextRootSalary, v[cur][x]);
			newIDX.insert(x);
		}
		for (auto& x : newIDX) { idx.erase(x); }

		int child = buildTree(newIDX, nextRootSalary);
		edges.push_back({ child, curRoot });
	}

	return curRoot;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n; k = n; v.resize(n, vector<int>(n)); res.resize(n); int ma = 0;
	for (auto& x : v) for (auto& y : x) { cin >> y; ma = max(ma, y); }
	for (int i = 0; i < n; i++) res[i] = v[i][i];

	set<int> idx; for (int i = 0; i < n; i++) idx.insert(i);
	int head = buildTree(idx, ma);

	cout << res.size() << '\n'; for (auto& x : res) 
		cout << x << ' '; cout << '\n';
	cout << head + 1 << '\n'; for (auto& e : edges) 
		cout << ++e.first << " " << ++e.second << '\n';

	cin.ignore(2); return 0;
}