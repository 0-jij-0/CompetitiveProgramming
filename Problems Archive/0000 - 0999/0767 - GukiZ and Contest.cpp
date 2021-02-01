#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<int> res;

int main() {
	int n; cin >> n; v.resize(n); res.resize(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v[i] = { x, i };
	}
	sort(v.rbegin(), v.rend());
	res[v[0].second] = 1; int rank = 1, inc = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].first == v[i - 1].first) { res[v[i].second] = rank; inc++; continue; }
		rank += inc; res[v[i].second] = rank; inc = 1;
	}
	for (auto &x : res) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}