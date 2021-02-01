#include <iostream>
#include <string>
using namespace std;

pair<string, int> period(string& s) {
	int n = (int)s.size();
	for (int i = 1; i < n; i++) {
		if (n % i) { continue; }
		bool ok = true;
		for(int j = i; j < n && ok; j += i)
			for(int k = 0; k < i && ok; k++)
				if (s[k] != s[k + j]) { ok = false; }
		if (ok) { return { s.substr(0, i), i }; }
	}
	return { "", -1 };
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }

int main() {
	int T; cin >> T; while (T--) {
		string s, t; cin >> s >> t;
		if (s.size() > t.size()) { swap(s, t); }
		if (s == t) { cout << s << '\n'; continue; }

		int n = (int)s.size(), m = (int)t.size();
		pair<string, int> p1 = period(s), p2 = period(t);
		if (p1.second == -1 && p2.first == s) { cout << t << '\n'; continue; }
		if (p1.second == -1 || p2.second == -1) { cout << -1 << '\n'; continue; }
		if (p1.first != p2.first) { cout << -1 << '\n'; continue; }

		int k = lcm(n / p1.second, m / p1.second);
		while (k--) cout << p1.first; cout << '\n';
	}
	cin.ignore(2); return 0;
}