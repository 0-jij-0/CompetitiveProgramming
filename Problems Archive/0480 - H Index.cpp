#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
	int t; cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		int n; cin >> n; cout << "Case #" << tc << ": ";
		vector<int> res; multiset<int> s; int ans = 0;
		for (int i = 0; i < n; i++) {
			while (!s.empty() && *s.begin() <= ans) { s.erase(s.begin()); }
			int a; cin >> a; if (a > ans) { s.insert(a); }
			if (s.size() > ans) { ans++; }
			res.push_back(ans);
		}
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i + 1 != n) { cout << ' '; }
			else { cout << endl; break; }
		}
	}
	cin.ignore(2); return 0;
}