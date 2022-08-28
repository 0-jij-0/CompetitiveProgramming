#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A, B;

struct vectorPartition {
	vector<int> A0, A1, B0, B1; vectorPartition() {}
};

vectorPartition check(int mask, vector<int>& a, vector<int>& b) {
	vectorPartition res;
	for (auto& x : a) (x & mask ? res.A1 : res.A0).push_back(x);
	for (auto& x : b) (x & mask ? res.B1 : res.B0).push_back(x);
	return (res.A0.size() == res.B1.size()) ? res : vectorPartition();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(1); B.resize(1);
		A[0].resize(n); for (auto& x : A[0]) cin >> x;
		B[0].resize(n); for (auto& x : B[0]) cin >> x;

		int res = 0;
		for (int b = 29; b >= 0; b--) {
			bool ok = true; vector<vector<int>> newA, newB;
			for (int i = 0; i < (int)A.size(); i++) {
				vectorPartition P = check(1 << b, A[i], B[i]);
				if (P.A0.empty() && P.A1.empty()) { ok = false; break; }
				if (!P.A0.empty()) { newA.push_back(P.A0); newB.push_back(P.B1); }
				if (!P.A1.empty()) { newA.push_back(P.A1); newB.push_back(P.B0); }
			}
			if (ok) { res |= 1 << b; A = move(newA); B = move(newB); }
		}

		cout << res << '\n';
	}
}