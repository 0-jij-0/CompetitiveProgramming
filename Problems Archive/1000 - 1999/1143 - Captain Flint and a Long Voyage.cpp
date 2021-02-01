#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; string res((n + 3) / 4, '8');
		res += string(n - res.size(), '9');
		reverse(res.begin(), res.end());
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}