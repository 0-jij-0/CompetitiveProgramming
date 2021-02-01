#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x; v.resize(n);
		for (auto &x : v) { cin >> x; }
		sort(v.rbegin(), v.rend());
		if (v[0] < x) { cout << 0 << endl; continue; }
		if (accumulate(v.begin(), v.end(), 0ll) / n >= x) { cout << n << endl; continue; }
		long long sum = v[0]; int i = 1;
		while (i < n) {
			if (sum / i < x) { break; }
			sum += v[i]; i++;
		}
		cout << i - 1 << endl;
	}
	cin.ignore(2); return 0;
}