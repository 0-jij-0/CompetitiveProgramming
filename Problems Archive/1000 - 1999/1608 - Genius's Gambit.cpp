#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, k; cin >> a >> b >> k;
	if (k == 0) { 
		string res = string(b, '1') + string(a, '0');
		cout << "Yes\n" << res << '\n' << res << '\n';
	}
	else if (b == 1 || a == 0) { cout << "No\n"; }
	else if (k <= a) {
		string RA(k + 1, '0'); RA[0] = '1';
		string RB = RA; reverse(RB.begin(), RB.end());
		string M(a - k, '0'), L(b - 1, '1');
		string A = L + M + RA, B = L + M + RB;
		cout << "Yes\n" << A << '\n' << B << '\n';
	}
	else if (k < b) {
		string R(a - 1, '0'), MA(k + 1, '1'); MA[k] = '0';
		string MB = MA; reverse(MB.begin(), MB.end());
		string L(b - k, '1');
		string A = L + MA + R, B = L + MB + R;
		cout << "Yes\n" << A << '\n' << B << '\n';
	}
	else if (b <= 2 || a <= 1 || (b + a - 2) < k) { cout << "No\n"; }
	else {
		string A = string(b, '1') + string(a, '0');
		string B = A; swap(B[1], B[a + b - 1]);

		int x = a + b - 2 - k; int i = a + b - 1;
		while (x--) { swap(B[i], B[i - 1]); i--; }
		cout << "Yes\n" << A << '\n' << B << '\n';
	}
	cin.ignore(2); return 0;
}