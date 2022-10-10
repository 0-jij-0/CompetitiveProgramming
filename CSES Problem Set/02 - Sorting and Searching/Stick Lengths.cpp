#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	int med = v[n / 2];
	for (auto &x : v) { x = abs(x - med); }
	cout << accumulate(v.begin(), v.end(), 0ll) << '\n';
}