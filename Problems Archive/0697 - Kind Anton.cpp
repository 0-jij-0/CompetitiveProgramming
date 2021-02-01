#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; a.resize(n); b.resize(n);
		for (auto &x : a) { cin >> x; }
		for (auto &x : b) { cin >> x; }
		bool inc = false, dec = false, check = true;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i] && !dec) { check = false; break; }
			if (a[i] < b[i] && !inc) { check = false; break; }
			inc = inc || (a[i] == 1); dec = dec || (a[i] == -1);
		}
		cout << (check ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}