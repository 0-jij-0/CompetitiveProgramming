#include <bits/stdc++.h>
using namespace std;
typedef double ld;

vector<int> v; ld res = 0.0;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	
	for(int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			int inv = 0;
			if (v[i] < v[j]) { inv = v[i] * (v[i] - 1) >> 1; }
			else {
				inv = v[j] * (v[j] - 1) >> 1;
				inv += (v[i] - v[j]) * v[j];
			}
			res += ((inv + 0.0) / (v[i] + 0.0)) / (v[j] + 0.0);
		}
	cout << fixed << setprecision(6) << res << '\n';
}