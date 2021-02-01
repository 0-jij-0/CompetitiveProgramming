#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long pref[100001];

int main() {
	for (long long i = 0; i <= 100000; i++) { pref[i] = i * (i - 1) / 2; }
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int f = lower_bound(pref, pref + 100001, k) - pref;
		int s = k - pref[f - 1]; string res(n, 'a');
		res[n - f] = res[n - s] = 'b'; cout << res << endl;
	}
	cin.ignore(2); return 0;
}