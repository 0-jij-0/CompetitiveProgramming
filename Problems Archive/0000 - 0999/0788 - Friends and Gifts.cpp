#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n; cin >> n; vector<int> a(n), b(n + 1, 0);
	for (auto &x : a) { cin >> x; b[x] = 1; }
	set<int> c;

	for (int i = 1; i <= n; i++)
		if (b[i] == 0) c.insert(i);

	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			if (c.find(i + 1) != c.end()) {
				int val = 0;
				for (auto &x : c) if (x != i + 1) { val = x; break; }
				a[i] = val;	c.erase(val);
			}

	auto it = c.begin();
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) { a[i] = *it; it++; }
		cout << a[i] << " ";
	}
	cout << endl; cin.ignore(2); return 0;
}