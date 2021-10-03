#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> comp, A, B, D, res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; res.resize(n);
	A.resize(n); B.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
		comp.push_back(A[i]);
		comp.push_back(A[i] + B[i]);
	}

	sort(comp.begin(), comp.end()); D.resize(4 * 100000 + 2);
	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	for (int i = 0; i < n; i++) {
		int L = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
		int R = lower_bound(comp.begin(), comp.end(), A[i] + B[i]) - comp.begin();
		D[L]++; D[R]--;
	}

	partial_sum(D.begin(), D.end(), D.begin());
	for (int i = 0; i <= 4 * 100000; i++) {
		if (D[i] == 0) { continue; }
		int cont = comp[i + 1] - comp[i];
		res[D[i] - 1] += cont;
	}

	for (auto& x : res) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}