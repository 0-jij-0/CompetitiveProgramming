#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> toLeft, A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; toLeft.resize(n);
	A.resize(n); for (auto& x : A) cin >> x;
	B.resize(n); for (auto& x : B) cin >> x;

	for (int i = 1; i < n; i++)
		toLeft[i] = toLeft[i - 1] + A[i - 1] - B[i - 1];

	nth_element(toLeft.begin(), toLeft.begin() + (n >> 1), toLeft.end());
	ll res = 0; for (auto& x : toLeft) res += abs(x - toLeft[n >> 1]);
	cout << res << '\n';
}