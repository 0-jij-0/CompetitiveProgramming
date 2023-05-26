#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, X; cin >> n >> X; A.resize(n);
	for (auto& x : A) cin >> x;

	bool ok = false;
	set<int> s(A.begin(), A.end());
	for (auto& x : s)
		ok = (ok || s.count(x - X));

	cout << (ok ? "Yes" : "No") << '\n';
}