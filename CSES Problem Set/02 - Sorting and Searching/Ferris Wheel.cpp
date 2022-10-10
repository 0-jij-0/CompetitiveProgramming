#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	int n, X; cin >> n >> X; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	int i = 0, j = n - 1, res = 0;
	while (i <= j)
		if (v[i] + v[j] > X) { j--; res++; }
		else { i++; j--; res++; }
	cout << res << '\n'; 
}