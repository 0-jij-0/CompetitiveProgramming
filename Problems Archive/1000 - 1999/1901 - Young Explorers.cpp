#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end());

		int res = 0, i = 0, cur = 0; 
		while (i < n) { 
			cur++; if (cur >= v[i]) { cur = 0; i++; res++; continue; }
			i++;
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}