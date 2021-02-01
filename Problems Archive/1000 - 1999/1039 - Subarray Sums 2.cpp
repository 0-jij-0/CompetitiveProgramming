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
	int x; cin >> n >> x; v.resize(n);
	for (auto &x : v) { cin >> x; }
	partial_sum(v.begin(), v.end(), v.begin());
	for (auto &x : v) { freq[x]++; }
	ll res = freq[x]; for (auto &y : v) {
		freq[y]--; res += freq[x + y];
	}
	cout << res << endl; cin.ignore(2); return 0;
}