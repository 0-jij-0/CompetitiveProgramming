#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> dp[2];
vector<int> A, B;

int main() {
	freopen("copy.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t; while (t--) {
		int n, W; ll X; cin >> n >> X >> W;
		dp[0].resize(W + 1); dp[1].resize(W + 1);
		A.resize(n); for (auto& x : A) { cin >> x; }
		B.resize(n); for (auto& x : B) { cin >> x; }

		fill(dp[0].begin(), dp[0].end(), -1);
		fill(dp[1].begin(), dp[1].end(), -1);
		int res = -1; bool ok = false; dp[0][0] = 0; 
		
		for (int i = 0; i < n; i++) {
			int icur = i & 1, inext = icur ^ 1;
			fill(dp[inext].begin(), dp[inext].end(), -1);

			for (int w = 0; w <= W; w++) {
				if (dp[icur][w] < 0) { continue; }
				if (dp[icur][w] >= X) { res = i; ok = true; break; }
				dp[inext][w] = max(dp[inext][w], dp[icur][w]);
				if ((w + A[i]) <= W) dp[inext][w + A[i]] = max(dp[inext][w + A[i]], B[i] + dp[icur][w]);
			} if (ok) break;
		}

		if (!ok) for (int w = 0; w <= W; w++)
			if (dp[n & 1][w] >= X) { res = n; break; }

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}