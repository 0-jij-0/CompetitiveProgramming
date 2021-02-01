#include <iostream>
#include <vector>
using namespace std;

vector<bool> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		v.clear(); v.resize(300, false);
		for (int i = 0; i < n; i++) {
			int a; cin >> a; v[a] = true;
		}
		int res = 0;
		for (int i = 1; i < 300; i++) {
			if (!v[i] && !x) { res = i - 1; break; }
			if (!v[i]) { x--; continue; }
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}
