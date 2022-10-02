#include <bits/stdc++.h>
using namespace std;

string dig = "0123456789ABCDEF";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	if (n < 16) { cout << "0" + string(1, dig[n]) << '\n'; }
	else { cout << string(1, dig[n / 16]) + string(1, dig[n % 16]) << '\n'; }
}