#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1000001, 0);

int main() {
	freopen("erase.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, res = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v[x] = 1;
	}
	for (int i = 1; i <= 1000000; i++) if (v[i]) {
		res++; for (int j = i; j <= 1000000; j += i) v[j] = 0;
	}

	cout << res << '\n';
}