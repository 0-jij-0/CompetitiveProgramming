#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end());

		ll A = 0, B = 0; bool b = true;
		for (int i = n - 1; i >= 0; i--, b ^= 1) {
			if (b && v[i] % 2) { continue; }
			if (b) { A += v[i]; continue; }
			if (v[i] % 2) { B += v[i]; continue; }
		}
		cout << (A == B ? "Tie" : (A > B ? "Alice" : "Bob")) << '\n';
	}
	cin.ignore(2); return 0;
}