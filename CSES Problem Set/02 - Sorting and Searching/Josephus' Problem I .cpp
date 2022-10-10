#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) { s.insert(i); }

	int cur = 1; while (s.size() != 1) {
		auto it = s.upper_bound(cur);
		if (it == s.end()) { it = s.begin(); }
		cout << *it << ' '; auto nextCur = it;
		nextCur++; if (nextCur == s.end()) { nextCur = s.begin(); }
		cur = *nextCur; s.erase(it);
	}

	cout << *s.begin() << '\n'; 
	cin.ignore(2); return 0;
}