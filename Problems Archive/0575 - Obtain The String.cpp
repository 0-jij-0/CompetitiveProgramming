#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s, t; cin >> s >> t;
		vector<int> c[26]; bool b = true;
		for (char &x : t) {
			if (!c[x - 'a'].empty()) { continue; }
			for (int i = 0; i < (int)s.size(); i++)
				if (s[i] == x) 
					c[x - 'a'].push_back(i);
			if (c[x - 'a'].empty()) { b = false; break; }
		}
		if (!b) { cout << -1 << endl; continue; }
		int i = -1, j = 0, res = 1;
		while (j != (int)t.size()) {
			auto it = lower_bound(c[t[j] - 'a'].begin(), c[t[j] - 'a'].end(), i + 1);
			if (it == c[t[j] - 'a'].end()) { i = -1; res++; continue; }
			i = *it; j++; continue;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}