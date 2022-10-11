#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; 
		A.resize(n); for (auto& x : A) cin >> x;
		B.resize(n); for (auto& x : B) cin >> x;

		int noPerm = 0;
		for (int i = 0; i < n; i++)
			noPerm += (A[i] != B[i]);

		int a = count(A.begin(), A.end(), 1);
		int b = count(B.begin(), B.end(), 1);
		cout << min(noPerm, 1 + abs(b - a)) << '\n';
	}
}