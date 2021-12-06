#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

vector<int> v;

ll countGoodSegments(int k) {
	if (k == 0) { return 0; }
	int j = 0, n = (int)v.size(); map<int, int> m; 
	ll res = 0; for (int i = 0; i < n; i++) {
		while (j != n && (m.size() < k || m.count(v[j]))) { m[v[j++]]++; }
		res += j - i; m[v[i]]--; if (m[v[i]] == 0) { m.erase(v[i]); }
	}
	return res;
}

int main() {
	int n, k; cin >> n >> k; v.resize(n);
	for (auto& x : v) { cin >> x; }

	cout << countGoodSegments(k) << '\n';
	cin.ignore(2); return 0;
}