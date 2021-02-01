#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<long long> v;
vector<int> powers;

int twonum(long long x) {
	int res = 0;
	while (x % 2 == 0) { x /= 2; res++; }
	return res;
}

int main() {
	powers.resize(65, 0);
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; powers[twonum(x)]++; }
	auto it = max_element(powers.begin(), powers.end());
	int idx = it - powers.begin();
	cout << v.size() - *it << endl;
	for (auto &x : v) {
		if (twonum(x) != idx) { cout << x << ' '; }
	}
	cout << endl; cin.ignore(2); return 0;
}