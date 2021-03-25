#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k >> s;
		int res = 0, last = -1, i = 0, j = -1;
		while (i != n) {
			if (s[i] != '*') { i++; continue; }
			if (res == 0) { last = j = i; i++; res++; continue; }
			if (i - j > k) { res++; j = last; continue; }
			last = i; i++;
		}
		for (i = n - 1; i >= 0; i--) 
			if (s[i] == '*') { res += j != i; break; }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}