#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ifstream ifs("mult.in");

	int t; ifs >> t; while (t--) {
		int n, k; ifs >> n >> k; v.resize(n);
		for (auto &x : v) { ifs >> x; }
		sort(v.rbegin(), v.rend()); ll res = 1;
		for (int i = 0; i < k; i++) res *= v[i];
		cout << res << '\n';
	}
	ifs.close(); return 0;
}