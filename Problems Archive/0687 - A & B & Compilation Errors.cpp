#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main() {
	int n; cin >> n; a.resize(n); b.resize(n - 1);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int e1 = 0, e2 = 0, i = 0;
	while (i != n - 1) {
		if (a[i] != b[i]) { e1 = a[i]; break; }
		i++;
	}
	if (e1 == 0) { e1 = a[n - 1]; }
	a = move(b); b.resize(n - 2);
	for (auto &x : b) { cin >> x; }
	sort(b.begin(), b.end()); i = 0;
	while (i != n - 2) {
		if (a[i] != b[i]) { e2 = a[i]; break; }
		i++;
	}
	if (e2 == 0) { e2 = a[n - 2]; }
	cout << e1 << endl << e2 << endl;
	cin.ignore(2); return 0;
}