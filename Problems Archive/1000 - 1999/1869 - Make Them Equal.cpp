#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s; char c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> c >> s;
		int cnt = count(s.begin(), s.end(), c);
		if (cnt == n) { cout << "0\n"; continue; }
		
		int one = -1;
		for (int i = 2; i <= n; i++) {
			int cnt2 = 0;
			for (int j = i - 1; j < n; j += i) cnt2 += s[j] != c;
			if (cnt2 == 0) { one = i; break; }
		}
		if (one > 0) { cout << "1\n" << one << '\n'; continue; }
		cout << "2\n" << n << ' ' << n - 1 << '\n';
	}
	cin.ignore(2); return 0;
}