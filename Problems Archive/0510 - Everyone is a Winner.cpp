#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int i = 1; vector<int> res;
		while (i < n + 2) {
			if (!res.empty() && (n / i) == res.back()) {
				for (int j = res.back() - 1; j >= 0; j--)
					res.push_back(j);
				break;
			}
			res.push_back(n / i); i++;
		}
		cout << (int) res.size() << endl;
		for (int j = (int) res.size() - 1; j >= 0; j--) { cout << res[j] << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}