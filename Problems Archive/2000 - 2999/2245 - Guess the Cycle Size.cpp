#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll query(ll a, ll b = 0) {
	if (!b) { cout << "! " + to_string(a) << endl; return 0; }
	cout << "? " + to_string(a) + " " + to_string(b) << endl;

	ll x; cin >> x; return x;
}

int main() {
	for (int i = 0; i < 25; i++) {
		ll x = query(i + 1, i + 2);
		ll y = query(i + 2, i + 1);
		if (x == -1) { query(i + 1); break; }
		if (x != y) { query(x + y); break; }
	}
}