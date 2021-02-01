#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> divisors[100001];
int mex[100001];

int main() {
	for (int i = 1; i <= 100000; i++)
		for (int j = 2 * i; j <= 100000; j += i)
			divisors[j].push_back(i);
	mex[0] = mex[1] = 0;
	for (int i = 2; i <= 100000; i++) {
		vector<bool> res(divisors[i].size() + 1, 0);
		for (int j = 0; j < (int)divisors[i].size(); j++) {
			int &y = divisors[i][j], z = i / y;
			if (y % 2 == 0) { res[0] = 1; continue; }
			res[mex[z]] = 1;
		}
		mex[i] = find(res.begin(), res.end(), false) - res.begin();
	}

	int t; cin >> t; while (t--) {
		int n; cin >> n; int res = 0;
		while (n--) { int x; cin >> x; res ^= mex[x]; }
		cout << (res ? 1 : 2) << '\n';
	}
	cin.ignore(2); return 0;
}