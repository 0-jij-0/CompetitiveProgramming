#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		if (n == 1 && v[0] % 2) { cout << -1 << endl; continue; }
		int s = accumulate(v.begin(), v.end(), 0);
		if (s % 2) {
			cout << n - 1 << endl; bool b = true;
			for (int i = 0; i < n; i++) {
				if (v[i] % 2 && b) { b = false; continue; }
				cout << i + 1 << ' ';
			}
			cout << endl; continue;
		}
		cout << n << endl;
		for (int i = 0; i < n; i++) { cout << i + 1 << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}