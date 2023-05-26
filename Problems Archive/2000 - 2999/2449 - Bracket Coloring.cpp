#include <bits/stdc++.h>
using namespace std;

bool isRegular(const string& s) {
	int pref = 0; for (char c : s) {
		pref += (c == '(' ? 1 : -1);
		if (pref < 0) return false;
	}
	return pref == 0;
}

bool isAntiRegular(string s) {
	reverse(s.begin(), s.end());
	return isRegular(s);
}

bool isBeautiful(const string& s) {
	return isRegular(s) || isAntiRegular(s);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; string s; cin >> n >> s; int dif = 0;
		for (char c : s) dif += (c == '(' ? 1 : -1);
		if (dif) { cout << "-1\n"; continue; }
		if (isBeautiful(s)) {
			cout << 1 << '\n';
			for (int i = 0; i < n; i++) cout << 1 << ' '; 
			cout << '\n'; continue;
		}
		cout << 2 << '\n';
		
		queue<int> close; stack<int> open;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') { open.push(i); ++dif; }
			else { close.push(i); --dif; }
			if (dif < 0) { close.pop(); ++dif; }
		}
		while (dif) { open.pop(); --dif; }
		vector<int> res(n, 2);
		while (!open.empty()) { res[open.top()] = 1; open.pop(); }
		while (!close.empty()) { res[close.front()] = 1; close.pop(); }
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
}