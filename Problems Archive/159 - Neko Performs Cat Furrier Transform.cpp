#include <iostream>
#include <vector>
using namespace std;

int logb2(int x) {
	int res = 0;
	while (x != 1) { res++; x /= 2; }
	return res;
}

bool check(int n) { return (logb2(n) != logb2(n + 1)); }

int main() {
	int x; cin >> x;
	vector<int> res; int op = 0;
	while (!check(x)) {
		int n = logb2(x); n++; res.push_back(n);
		n = (1 << n) - 1;
		x = x ^ n; op++; if (check(x)) { break; }
		x++; op++;
	}
	cout << op << endl;
	for (unsigned int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i + 1 != res.size()) { cout << " "; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}