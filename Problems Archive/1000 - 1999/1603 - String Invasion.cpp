#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

string s, t; vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; int n = (int)s.size();

	ll res = 0; 
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != s[i + 1] || s[i] == s[i + 2]) {
			t.push_back(s[i]); v.push_back(i); continue;
		}
		
		t.pop_back(); v.pop_back();
		int j = i + 1; while (!t.empty()) {
			if (s[i] == t.back()) { 
				j = v.back(); t.pop_back(); 
				v.pop_back(); continue;
			}
			res += v.back() - j; j = v.back();
			t.pop_back(); v.pop_back();
		}
		t.push_back(s[i]); v.push_back(j);
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}