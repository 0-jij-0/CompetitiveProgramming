#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main() {
	int n; cin >> n; a.resize(n); b.resize(n);
	for (auto &x : a) { cin >> x; }
	for (auto &x : b) { cin >> x; }
	reverse(b.begin(), b.end()); 
	
	int l = 0, r = 0;
	while (l < n && a[l] != b[l]) { l++; r++; }
	while (r < n && a[r] == b[r]) { r++; }
	for (int i = 0; i < n && l != r; i++)
		if (a[i] != a[l] && b[i] != b[l]) 
			swap(b[l++], b[i]);

	if (l != r) { cout << "No" << '\n'; return 0; }
	cout << "Yes" << '\n';
	for (auto &x : b) cout << x << ' ';
	cout << '\n'; cin.ignore(2); return 0;
}