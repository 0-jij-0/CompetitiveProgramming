#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; 
	int cur = n; v.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (--a > --b) { swap(a, b); }
		cur -= v[a]++ == 0;
	}

	int q; cin >> q; while (q--) {
		int t; cin >> t; if (t == 3) {
			cout << cur << '\n'; continue;
		}
		int a, b; cin >> a >> b;
		if (--a > --b) { swap(a, b); }
		t == 1 ? cur -= v[a]++ == 0 : cur += --v[a] == 0;
	}
	cin.ignore(2); return 0;
}