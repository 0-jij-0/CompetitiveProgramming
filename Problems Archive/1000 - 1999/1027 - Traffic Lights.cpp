#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> s; multiset<int> L;

int main() {
	int x, n; cin >> x >> n;
	s.insert(0); s.insert(x); L.insert(x);
	while (n--) {
		int p; cin >> p; 
		auto it = --s.lower_bound(p);
		auto l = it, r = ++it;
		L.erase(L.find(*r - *l)); s.insert(p);
		L.insert(p - *l); L.insert(*r - p);
		cout << *L.rbegin() << endl;
	}
	cin.ignore(2); return 0;
}