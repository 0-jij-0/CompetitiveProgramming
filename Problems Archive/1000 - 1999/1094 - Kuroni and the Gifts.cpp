#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b; 

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; a.resize(n); b.resize(n);
		for (auto &x : a) { cin >> x; }
		for (auto &x : b) { cin >> x; }
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (auto &x : a) cout << x << ' '; cout << '\n';
		for (auto &x : b) cout << x << ' '; cout << '\n';		
	}
	cin.ignore(2); return 0;
}