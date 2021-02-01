#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> c, t;

int main() {
	int n; cin >> n;
	c.resize(n); t.resize(n);
	for (auto &x : c) { cin >> x; }
	for (auto &x : t) { cin >> x; }
	adjacent_difference(c.begin(), c.end(), c.begin());
	adjacent_difference(t.begin(), t.end(), t.begin());
	bool b = c.front() == t.front();
	sort(c.begin(), c.end()); sort(t.begin(), t.end());
	for (int i = 0; i < n; i++) { b = b && (c[i] == t[i]); }
	cout << ((b) ? "Yes" : "No") << endl;
	cin.ignore(2); return 0;
}