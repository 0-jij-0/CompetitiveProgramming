#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s; int n = (int)s.size();
		vector<ll> v(n); v[0] = (s[0] == '+') ? 1 : -1;
		for (int i = 1; i < n; i++)
			v[i] = v[i - 1] + (s[i] == '+' ? 1 : -1);
		ll res = 0; ll cur = 0;
		for (int i = 0; i < n; i++)
			if (cur < -v[i]) { res += -(cur + v[i])*(i + 1); cur = -v[i]; continue; }
		cout << res + n << '\n';
	}
	cin.ignore(2); return 0;
}