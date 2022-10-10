#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
typedef long long ll;

vector<ll> v; int n;
map<ll, int> freq;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	partial_sum(v.begin(), v.end(), v.begin());
	for (auto &x : v) { x = ((x % n) + n) % n; freq[x]++; }
	ll res = freq[0]; for (auto &x : v) {
		freq[x]--; res += freq[x];
	}
	cout << res << endl; cin.ignore(2); return 0;
}