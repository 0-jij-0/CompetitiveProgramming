#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll n; cin >> n; int i = 1, res = 0; 
		while (true) {
			ll req = (1 << i) - 1;
			req = req * (req + 1) / 2;
			if (n < req) { break; }
			n -= req; res++; i++;
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}