#include <bits/stdc++.h>
using namespace std;

vector<int> v, a;

int main() {
	int n; cin >> n; v.resize(n); a.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; a[--v[i]] = i; }
	int res = 1; for (int i = 1; i < n; i++) res += a[i] < a[i - 1];
	cout << res << '\n';
}