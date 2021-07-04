#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll k; cin >> n >> k;
	v.resize(n); int cur = n;
	int inv = n - 1, i = 0;
	while (cur != 0) {
		if (k >= inv) { k -= inv--; v[i++] = cur--; continue; }
		v[n - k - 1] = cur; int x = 1;
		cur = 0; for (int j = i; j < n; j++)
			if (j != n - k - 1) { v[j] = x++; }
	}

	for (auto& x : v) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}