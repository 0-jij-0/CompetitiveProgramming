#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; p.resize(n);
		for (auto &x : p) { cin >> x; }
		n /= 2; int x = p[n];
		while (!p.empty() && (p.size() != n || p.back() == x)) { p.pop_back(); }

		n = (int)p.size();
		int g = 1; while (g < n && p[g] == p[g - 1]) { g++; }
		if (g == n) { cout << "0 0 0" << endl; continue; }

		int b = g + 1; while (b < n - 1 && p[n - b - 1] == p[n - b]) { b++; }

		int s = n - g - b; bool c = g < min(s, b);
		if (c) { cout << g << ' ' << s << ' ' << b << endl; }
		else { cout << "0 0 0" << endl; }
	}
	cin.ignore(2); return 0;
}