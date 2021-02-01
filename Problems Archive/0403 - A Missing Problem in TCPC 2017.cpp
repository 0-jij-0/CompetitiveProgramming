#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v.clear(); v.resize(n, 0);
		for (int i = 0; i < n - 1; i++) {
			int k; cin >> k; v[k] = 1;
		}
		for (int i = 1; i <= n; i++)
			if (!v[i]) { cout << i << endl; break; }
	}
	cin.ignore(2); return 0;
}