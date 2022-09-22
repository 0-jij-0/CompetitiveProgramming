#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v; int n, k;

bool check(int M) {
	int res = 0; int prev = -M;
	for (auto& x : v) {
		if (x - prev < M) { continue; }
		res++; prev = x;
	}
	return res >= k;
}

int maxMinDistance() {
	int L = 0, R = 1 << 30;
	while (L != R) {
		int M = (L + R + 1) >> 1;
		check(M) ? L = M : R = M - 1;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;
	cout << maxMinDistance() << '\n';
}