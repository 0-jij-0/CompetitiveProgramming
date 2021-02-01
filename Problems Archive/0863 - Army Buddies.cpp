#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> L, R;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int s, b; cin >> s >> b; 
	while (s + b != 0) {
		L.resize(s); iota(L.begin(), L.end(), -1); L[0] = s + 1;
		R.resize(s); iota(R.begin(), R.end(), 1); R[s - 1] = s + 1;

		while (b--) {
			int l, r; cin >> l >> r; l--; r--;
			if (L[l] == s + 1) { cout << '*'; } else { cout << L[l] + 1; } cout << ' ';
			if (R[r] == s + 1) { cout << '*'; } else { cout << R[r] + 1; } cout << '\n';
			if (R[r] != s + 1) { L[R[r]] = L[l]; }
			if (L[l] != s + 1) { R[L[l]] = R[r]; }
		}
		cout << '-' << '\n'; cin >> s >> b;
	}
	cin.ignore(2); return 0;
}
