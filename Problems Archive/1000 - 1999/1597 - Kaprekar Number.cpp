#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

ll kaprekarNumber(ll &x) {
	string s = to_string(x);
	sort(s.rbegin(), s.rend());
	ll b = stoll(s);
	reverse(s.begin(), s.end());
	ll a = stoll(s);
	return b - a;
}

int main() {
	ll n; int k; cin >> n >> k;
	for (int i = 1; i <= k; i++)
		n = kaprekarNumber(n);
	cout << n << '\n';
	cin.ignore(2); return 0;
}