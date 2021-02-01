#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.begin(), v.end()); int s = 0; 
		for (auto &x : v) { s += x; }
		if (n == 1) { cout << 'T' << '\n'; continue; }
		if (s == n) { cout << (n & 1 ? "T" : "HL") << '\n'; continue; }
		if (v.back() > s - v.back()) { cout << 'T' << '\n'; continue; }
		cout << (s & 1 ? "T" : "HL") << '\n';
	} 
	cin.ignore(2); return 0;
}