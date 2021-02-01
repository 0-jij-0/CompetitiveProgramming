#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int n; cin >> n; v.resize(n); ll res = 0;
	for (auto &x : v) { cin >> x; }
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			for (int k = j; k < n; k++)
				res = max(res, v[i] | v[j] | v[k]);
	cout << res << endl; cin.ignore(2); return 0;
}