#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x.second >> x.first; }
	sort(v.begin(), v.end()); int cur = 0, res = 0;
	for (auto &x : v) {
		if (x.second < cur) { continue; }
		res++; cur = x.first;
	}
	cout << res << endl; cin.ignore(2); return 0;
}