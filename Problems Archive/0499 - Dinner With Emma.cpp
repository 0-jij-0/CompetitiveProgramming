#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

int main() {
	int n, m; cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (auto &x : v)
		for (auto &y : x)
			cin >> y;
	int res = 0;

	for (int i = 0; i < n; i++)
		res = max(res, *min_element(v[i].begin(), v[i].end()));
	cout << res << endl;
	cin.ignore(2); return 0;
}