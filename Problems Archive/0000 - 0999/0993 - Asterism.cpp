#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> v, freq;
int n; ll p;

bool check(const int &x) {
	ll res = 1; int done = 0;
	for (int i = 0; i < n; i++) {
		if (freq[min(x + i, 2000)] - i <= 0) { return false; }
		res = (res * (freq[min(x + i, 2000)] - i)) % p;
		if (res == 0) { return false; }
	}
	return true;
}

int main() {
	cin >> n >> p; v.resize(n); freq.resize(2001, 0);
	for (auto &x : v) { cin >> x; freq[x]++; }
	partial_sum(freq.begin(), freq.end(), freq.begin());
	vector<int> res;
	for (int i = 0; i <= 2000; i++)
		if (check(i)) res.push_back(i);
	cout << res.size() << '\n';
	for (auto &x : res) cout << x << ' ';
	cout << '\n'; cin.ignore(2); return 0;
}