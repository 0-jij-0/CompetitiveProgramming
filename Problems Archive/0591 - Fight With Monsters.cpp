#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> hp, v;

int main() {
	int n, a, b, k; cin >> n >> a >> b >> k;
	hp.resize(n); v.resize(n);
	for (auto &x : hp) { 
		cin >> x; x %= a + b;
		if (!x) { x = a + b; }
	}
	for (int i = 0; i < n; i++) {
		v[i] = max(0, (hp[i] - 1) / a);
	}
	sort(v.begin(), v.end());
	int pref = 0, i = 0;
	while (i < n && pref + v[i] <= k) {
		pref += v[i]; i++;
	}
	cout << i << endl; cin.ignore(2); return 0;	
}