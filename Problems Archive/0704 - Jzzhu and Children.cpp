#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<pair<int, int>> res;

int main() {
	int n, m; cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	for (int i = 0; i < n; i++) res.push_back({ (v[i] + m - 1) / m, i });
	cout << max_element(res.begin(), res.end())->second + 1 << endl;
	cin.ignore(2); return 0;
}