#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
	int l, q; cin >> l >> q;
	s.insert(0); s.insert(l);

	while (q--) {
		int c, x; cin >> c >> x;
		if (c == 1) { s.insert(x); continue; }
		auto it = s.lower_bound(x); auto itt = it; itt--;
		cout << *it - *itt << '\n';
	}

	cin.ignore(2); return 0;
}