#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> a, b; int n, m;
map<int, int> freq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; a.resize(n);
	int m; cin >> m; b.resize(m);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }

	int r = 0, res = 0;
	for (auto &x : a) for (auto &y : b) if (y >= x) freq[y - x]++;
	for (auto &x : freq) if (r < x.second) { r = x.second; res = x.first; }
	cout << res << endl; cin.ignore(2); return 0;
}