#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> manacher(string& s, bool even) {
	int n = s.size(); vector<int> res(n);
	int l = 0, r = -1; for (int i = 0; i < n; i++) {
		int k = i > r ? 1 : min(res[l + r - i + even], r - i + even) + 1;
		while (i + k - even < n && i - k >= 0 && s[i + k - even] == s[i - k]) { k++; }
		res[i] = --k; if (i + k - even > r) { l = i - k; r = i + k - even; }
	}
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s; int n = (int)s.size();
	vector<int> e = manacher(s, 1), o = manacher(s, 0);

	int cE = max_element(e.begin(), e.end()) - e.begin();
	int cO = max_element(o.begin(), o.end()) - o.begin();
	string E = s.substr(cE - e[cE], e[cE] << 1);
	string O = s.substr(cO - o[cO], o[cO] << 1 | 1);

	cout << (E.size() < O.size() ? O : E) << '\n';
}
