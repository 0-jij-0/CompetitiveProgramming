#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> a, res;
map<int, int> b;

bool check(int x, map<int, int> m) {
	m[x ^ a[0]]--;
	for(int i = 1; i < (int)a.size(); i++)
		if (m[x ^ a[i]]) { m[x ^ a[i]]--; }
		else { return false; }
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; a.resize(n);
	for (auto& x : a) cin >> x;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; b[x]++;
	}

	for (auto& x : b) 
		if (check(a[0] ^ x.first, b))
			res.push_back(a[0] ^ x.first);

	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto& x : res) cout << x << '\n';
	cin.ignore(2); return 0;
}