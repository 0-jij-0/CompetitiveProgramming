#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v, l;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); l.resize(n);
		for (auto &x : v) { cin >> x; }
		for (auto &x : l) { cin >> x; }
		vector<int> u; int j = 0;
		for (int i = 0; i < n; i++)
			if (!l[i]) u.push_back(v[i]);
		sort(u.rbegin(), u.rend());
		for(int i = 0; i < n; i++)
			if (!l[i]) v[i] = u[j++];

		for (auto &x : v) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}