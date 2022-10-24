#include <bits/stdc++.h>
using namespace std;

int findLen(int a, int b) {
	int res = 0; while (a != b) {
		res += (a / (b + 1));
		a %= (b + 1); swap(a, b);
	}
	return a ? 1 << 30 : res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; int A = 0, len = n;
	for (int a = (n + 1) / 2; a <= n; a++) {
		int L = findLen(a, n - a);
		if (L < len) { A = a; len = L; }
	}

	string res = "";
	for (int B = n - A, bit = 0; A || B; bit ^= 1) {
		res += string(A / (B + 1), bit ? '1' : '0');
		A %= (B + 1); swap(A, B);
	}

	cout << res << '\n';
}