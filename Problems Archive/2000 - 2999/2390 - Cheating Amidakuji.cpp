#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m; A.resize(m);
	for (auto& x : A) { cin >> x; --x; }

	vector<int> prv(n), nxt(n), idxN(n), idxP(n);
	iota(prv.begin(), prv.end(), 0);
	iota(nxt.begin(), nxt.end(), 0);
	iota(idxN.begin(), idxN.end(), 0);
	iota(idxP.begin(), idxP.end(), 0);

	for (int i = 0; i < m; i++)
		swap(nxt[A[i]], nxt[A[i] + 1]);

	for (int i = 0; i < n; i++) idxN[nxt[i]] = i;
	for (int i = 0; i < n; i++) idxP[i] = i;

	for (int i = 0; i < m; i++) {
		int X = A[i];
		swap(idxN[X], idxN[X + 1]);
		cout << idxN[idxP[0]] + 1 << '\n';
		swap(idxP[prv[X]], idxP[prv[X + 1]]);
		swap(prv[X], prv[X + 1]);
	}
}