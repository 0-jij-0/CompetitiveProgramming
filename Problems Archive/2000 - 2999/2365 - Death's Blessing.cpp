#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(n); B.resize(n);
		for (auto& x : A) cin >> x;
		for (auto& x : B) cin >> x;

		ll sumA = accumulate(A.begin(), A.end(), 0ll);
		ll sumB = accumulate(B.begin(), B.end(), 0ll);
		ll maxB = *max_element(B.begin(), B.end());
		cout << sumA + sumB - maxB << '\n';
	}
}