#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool isPrime(int x) {
	if (x < 2) { return false; }
	if (x < 4) { return true; }

	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); int sum = 0;
		for (auto& x : v) { cin >> x; sum += x; }
		if (!isPrime(sum)) {
			cout << n << '\n';
			for (int i = 0; i < n; i++)
				cout << i + 1<< ' '; cout << '\n';
			continue;
		}
		bool skip = true; cout << n - 1 << '\n';
		for (int i = 0; i < n; i++) {
			if (skip && v[i] % 2) { skip = false; continue; }
			cout << i + 1 << ' ';
		}
		cout << '\n';
	}
	cin.ignore(2); return 0;
}