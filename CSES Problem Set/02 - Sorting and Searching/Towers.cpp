#include <bits/stdc++.h>
using namespace std;

vector<int> v; multiset<int> s;

int main() {
	int n; cin >> n; v.resize(n); int res = 0;
	for (auto &x : v) { 
		cin >> x; auto it = s.upper_bound(x);
		if (it == s.end()) { s.insert(x); continue; }
		s.erase(it); s.insert(x);
	}
	cout << s.size() << '\n';
}