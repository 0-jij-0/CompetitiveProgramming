#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> posA, posB, negA, negB;

int solve(vector<int>& A, vector<int>& B) {
	if (A.empty() || B.empty()) { return 0; }
	A.push_back(1 << 30); vector<int> C(A.size()); 
	
	int i = 0, j = 0;
	while (i != (int)A.size() && j != (int)B.size()) {
		if (A[i] < B[j]) { i++; continue; }
		if (A[i] > B[j]) { j++; continue; }
		C[i] = 1; i++; j++;
	}

	partial_sum(C.rbegin(), C.rend(), C.rbegin());

	i = 0; j = 0; int res = C[0];
	while (j != (int)B.size() && B[j] < A[0]) { j++; }
	while (i < (int)A.size() && j < (int)B.size()) {
		if (A[i] <= B[j] + i) { i++; continue; }
		int k = upper_bound(A.begin(), A.end(), B[j] + i) - A.begin();
		int y = lower_bound(B.begin(), B.end(), B[j] + i) - B.begin();
		res = max(res, y - j + (k == (int)A.size() ? 0 : C[k])); j++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		posA.clear(); posB.clear(); 
		negA.clear(); negB.clear();
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			(x < 0 ? negA : posA).push_back(abs(x));
		}

		for (int i = 0; i < m; i++) {
			int x; cin >> x;
			(x < 0 ? negB : posB).push_back(abs(x));
		}

		reverse(negA.begin(), negA.end());
		reverse(negB.begin(), negB.end());

		cout << solve(posA, posB) + solve(negA, negB) << '\n';
	}
	cin.ignore(2); return 0;
}