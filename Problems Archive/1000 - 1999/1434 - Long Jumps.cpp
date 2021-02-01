#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;
vector<ll> dp;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); 
		dp.clear(); dp.resize(n + 1, 0);
		for (auto& x : v) { cin >> x; }
		for (int i = n - 1; i >= 0; i--) dp[i] = v[i] + dp[min(n, i + v[i])];
		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}
	cin.ignore(2); return 0;
}