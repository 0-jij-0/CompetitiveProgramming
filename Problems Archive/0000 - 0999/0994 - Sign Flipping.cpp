#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n); bool neg = false;
		for (auto &x : v) { cin >> x; }
		for (auto &x : v) { cout << ((neg = !neg) ? -abs(x) : abs(x)) << ' '; }
		cout << '\n';
	}
	cin.ignore(2); return 0;
}