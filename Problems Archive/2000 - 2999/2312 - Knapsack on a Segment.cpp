#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> W, C;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, s; cin >> n >> s;
	W.resize(n); for (auto& x : W) cin >> x;
	C.resize(n); for (auto& x : C) cin >> x;

	ll res = 0, curC = 0; int curW = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && curW + W[j] <= s) { curW += W[j]; curC += C[j++]; }
		res = max(res, curC); curW -= W[i]; curC -= C[i];
	}

	cout << res << '\n';
}