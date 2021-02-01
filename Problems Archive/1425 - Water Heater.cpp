#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v(200001, 0);

int main() {
	int n, w; cin >> n >> w; while (n--) {
		int s, t, p; cin >> s >> t >> p;
		v[s] += p; v[t] -= p;
	}
	partial_sum(v.begin(), v.end(), v.begin());
	bool ok = *max_element(v.begin(), v.end()) <= w;
	cout << (ok ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}