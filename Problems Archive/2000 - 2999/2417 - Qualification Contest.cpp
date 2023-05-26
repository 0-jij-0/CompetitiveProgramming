#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k; cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.begin() + k);
	for (int i = 0; i < k; i++)
		cout << v[i] << '\n';
}