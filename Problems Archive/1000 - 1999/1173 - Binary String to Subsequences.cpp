#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> ans;

int main() {
	int t; cin >> t; while (t--) {
		int n; string s; cin >> n >> s;
		set<int> z, o;  ans.resize(n);
		for (int i = 0; i < n; i++)
			(s[i] - '0' ? o : z).insert(i);

		int i = 0; while(!z.empty() || !o.empty()) {
			set<int> now; int cur = -1; bool b;
			if (o.empty())  b = true;
			else if (z.empty()) b = false; 
			else b = (*z.begin() < *o.begin());
			while (true) {
				if (b) {
					auto it = z.lower_bound(cur);
					if (it == z.end()) { break; }
					cur = *it; now.insert(cur); b ^= 1;
				}
				else {
					auto it = o.lower_bound(cur);
					if (it == o.end()) { break; }
					cur = *it; now.insert(cur); b ^= 1;
				}
			}
			i++; for (auto &x : now) { ans[x] = i; z.erase(x); o.erase(x); }
		}
		cout << i << '\n';
		for (auto &x : ans) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}