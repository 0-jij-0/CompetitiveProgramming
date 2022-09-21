#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> A; int K;

bool check(ll M) {
	ll res = 0;
	for (auto& x : A) res += min(M, x);
	return res >= M * K;
}

ll maxNumCouncils() {
	ll L = 0, R = 1ll << 40;
	while (L != R) {
		ll M = (L + R + 1) >> 1;
		check(M) ? L = M : R = M - 1;
	}
	return L;
}

int main() {
	int n; cin >> K >> n; A.resize(n);
	for (auto& x : A) { cin >> x; }
	cout << maxNumCouncils() << '\n';
}