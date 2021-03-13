#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, L, R;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	L.resize(n, 0); R.resize(n, 0);

	for (int i = 0; i < n - 1; i++) {
		if (v[i] < v[i + 1]) { continue; }
		int j = i; while (j != n - 1 && v[j] > v[j + 1]) { j++; }
		for (int k = i; k <= j; k++) R[k] = j - k; i = j;
	}

	for (int i = n - 1; i > 0; i--) {
		if (v[i] < v[i - 1]) { continue; }
		int j = i; while (j != 0 && v[j] > v[j - 1]) { j--; }
		for (int k = i; k >= j; k--) L[k] = k - j; i = j;
	}

	int idxL = max_element(L.begin(), L.end()) - L.begin();
	int idxR = max_element(R.begin(), R.end()) - R.begin();
	bool a = count(L.begin(), L.end(), L[idxL]) == 1;
	bool b = count(R.begin(), R.end(), R[idxR]) == 1;
	int res = a && b && (idxL == idxR) && (L[idxL] == R[idxR]) && (L[idxL] % 2 == 0);

	cout << res << '\n';
	
	cin.ignore(2); return 0;
}