#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	while (n) {
		multiset<ll> s;
		for (int i = 0; i < n; i++) { 
			int x; cin >> x; s.insert(x);
		}
		ll res = 0;
		while (s.size() > 1) {
			ll x = *s.begin(); s.erase(s.begin());
			x += *s.begin(); s.erase(s.begin());
			res += x; s.insert(x);
		}
		cout << res << endl; cin >> n;
	}
	cin.ignore(2); return 0;
}