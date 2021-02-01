#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void generate(int n, vector<int> &v) {
	if (n == 1) { for (auto &x : v) cout << x << ' '; cout << '\n'; return; }
	for (int i = 0; i < n; i++) {
		generate(n - 1, v); if (i != n - 1)
			for (int i = n % 2; i < n; i += 2)
				swap(v[i], v[i + 1]);
	}
}

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n); 
	iota(v.begin(), v.end(), 1);
	generate(n, v); cin.ignore(2); return 0;
}