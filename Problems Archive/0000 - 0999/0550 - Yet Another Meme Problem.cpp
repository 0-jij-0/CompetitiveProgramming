#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll A, B; cin >> A >> B;
		ll res = 0, t = 9;
		while (t <= B) { res += A; t = 10 * t + 9; }
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}