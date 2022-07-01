#include <iostream>
using namespace std;

bool query(int x) {
	cout << x << endl;
	int r; cin >> r;
	return r;
}

int inverse(int n, int k) {
	int res = 0, z = 1;
	while (n) {
		int cur = n % k; cur = (k - cur) % k;
		res += cur * z; n /= k; z *= k;
	}
	return res;
}

int xorK(int x, int y, int k) {
	int res = 0, z = 1;
	while (x || y) {
		int cur = ((x % k) + (y % k)) % k;
		res += cur * z; x /= k; y /= k; z *= k;
	}
	return res;
}

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		if (query(0)) { continue; }

		for (int i = 1; i < n; i++) {
			int q = i & 1 ? xorK(inverse(i, k), i - 1, k) : xorK(i, inverse(i - 1, k), k);
			if (query(q)) break;
		}
	}
}