#include <iostream>
using namespace std;
typedef long long ll;

ll findSmallestSquareSize(int n, int w, int h) {
	ll l = max(w, h), r = 1ll << 60;
	while (l != r) {
		ll M = (l + r) >> 1, V = M / h;
		((n + V - 1) / V) * w <= M ? r = M : l = M + 1;
	}
	return l;
}

int main() {
	int w, h, n; cin >> w >> h >> n;
	cout << findSmallestSquareSize(n, w, h) << '\n';
}