#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> freq;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; freq.clear(); freq.resize(10001, 0);
		while (n--) { int x; cin >> x; freq[x]++; }
		int res = 0; for (int i = 0; i < 10000; i++)
			res = max(res, freq[i] + freq[i + 1]);
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}