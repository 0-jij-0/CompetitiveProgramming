#include <iostream>
#include <vector>
using namespace std;

int weight(int x) {
	int res = 0;
	while (x) { res++; x = x & (x - 1); }
	return res;
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> v(m);
	for (auto &x : v) { cin >> x; }
	int me; cin >> me; int res = 0;
	for (auto &x : v) res += (weight(me ^ x) <= k);
	cout << res << endl;
	cin.ignore(2); return 0;
}