#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; int g = 0, last = 0;
		while (n--) { cin >> last; g = gcd(g, last); }
		cout << last / g << '\n';
	}
}