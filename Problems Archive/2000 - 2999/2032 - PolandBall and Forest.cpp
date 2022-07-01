#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v; set<int> s;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) cin >> x;

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == i + 1) { res++; }
		else { s.insert(v[i]); }
	}

	cout << res + s.size() / 2 << endl;
}