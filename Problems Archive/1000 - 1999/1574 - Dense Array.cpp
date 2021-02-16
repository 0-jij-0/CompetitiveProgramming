#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		int res = 0;
		for (int i = 1; i < n; i++) {
			int a = (v[i] < v[i - 1]) ? v[i] : v[i - 1];
			int b = (v[i] < v[i - 1]) ? v[i - 1] : v[i];
			while ((b + a - 1) / a > 2) { res++; a <<= 1; }
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}