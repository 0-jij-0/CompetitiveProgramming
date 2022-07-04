#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x; A.resize(n); B.resize(n);
	for (int i = 0; i < n; i++) cin >> A[i] >> B[i];

	ll res = 1ll << 60, cur = 0, rem = x;
	for (int i = 0; i < n && rem; i++, rem--) {
		res = min(res, cur + A[i] + rem * B[i]);
		cur += A[i] + B[i];
	}

	cout << res << '\n';
}