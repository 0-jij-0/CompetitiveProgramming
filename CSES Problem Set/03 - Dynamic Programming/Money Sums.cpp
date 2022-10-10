#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; bitset<N> dp(1);
	while (n--) { int x; cin >> x; dp |= dp << x; }
	cout << dp.count() - 1 << '\n';
	for (int i = 1; i < N; i++)	if (dp[i]) 
		cout << i << ' '; cout << '\n';
}