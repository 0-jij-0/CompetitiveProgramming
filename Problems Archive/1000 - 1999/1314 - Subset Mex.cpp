#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; vector<int> freq(102, 0);
		for (int i = 0; i < n; i++) { int x; cin >> x; freq[x]++; }
		bool two = true; int res = 0;
		for (int i = 0; i < 102; i++) {
			if (freq[i] > two) { continue; }
			if (two && freq[i]) { res += i; two = false; continue; }
			if (two) { res = 2 * i; break; }
			res += i; break;
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}