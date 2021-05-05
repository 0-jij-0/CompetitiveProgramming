#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v; string s;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n >> s; v.clear();
		for (int i = 0; i < n; i++)
			if (s[i] == '*')v.push_back(i);

		ll res = accumulate(v.begin(), v.end(), 0ll);
		ll lC = 0, left = 0, rC = (int)v.size(), right = res - rC * (rC - 1) / 2;
		int j = 0, i = 0; while (j != (int)v.size()) {
			if (i == v[j]) { lC++; rC--; j++; }
			else { left += lC; right -= rC; } 
			i++; res = min(res, left + right);
		}
		cout << min(res, left) << '\n';
	}
	cin.ignore(2); return 0;
}