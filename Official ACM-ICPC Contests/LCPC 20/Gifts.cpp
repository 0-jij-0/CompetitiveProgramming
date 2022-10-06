#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("fair.in", "r", stdin);

	int n; cin >> n;
	int s1 = 0, s2 = 0;
	vector<int> a(n); for (auto& x : a) { cin >> x; s1 += x; }
	vector<int> b(n); for (auto& x : b) { cin >> x; s2 += x; }

	if (s1 == s2) { cout << "fair" << '\n'; }
	else { cout << "not fair" << '\n'; }
}