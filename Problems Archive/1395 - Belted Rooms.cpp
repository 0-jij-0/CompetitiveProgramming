#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s; vector<int> res;

bool checkCycle() {
	int n = (int)s.size();
	if (count(s.begin(), s.end(), '-') == n) { return true; }
	int idx = find(s.begin(), s.end(), '>') - s.begin();
	if (idx == n) { idx = find(s.begin(), s.end(), '<') - s.begin(); }

	if (s[idx] == '>') {
		int i = (idx + 1) % n;
		for(; i != idx; i = (i + 1) % n)
			if (s[i] == '<') { break; }
		return i == idx;
	}
	int i = (idx - 1 + n) % n;
	for(; i != idx; i = (i - 1 + n) % n)
		if (s[i] == '>') { break; }
	return i == idx;
}

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n >> s; res.clear();
		if (checkCycle()) {	cout << n << '\n'; continue; }
		res.resize(n, 0); for (int i = 0; i < n; i++)
			if (s[i] == '-') res[i] = res[(i + 1) % n] = 1;
		cout << count(res.begin(), res.end(), 1) << '\n';
	}
	cin.ignore(2); return 0;
}