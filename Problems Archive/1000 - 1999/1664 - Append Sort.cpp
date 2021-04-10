#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool operator < (string& a, string& b) {
	int n = (int)a.size(), m = (int)b.size();
	if (n < m) { return true; }
	if (m < n) { return false; }

	for (int i = 0; i < n; i++)
		if (a[i] < b[i]) return true;
		else if (a[i] > b[i]) return false;
	return false;
}

string addOne(string s) {
	int n = (int)s.size(), i = n - 1;
	while (i >= 0) {
		s[i] = ((s[i] - '0' + 1) % 10) + '0';
		if (s[i] != '0') break; i--;
	}
	return move(s);
}

vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		int res = 0; for (int i = 1; i < n; i++) {
			int A = (int)v[i - 1].size(), B = (int)v[i].size(), k = A - B;
			if (v[i - 1] < v[i]) { continue; }
			if (A == B) { res++; v[i].push_back('0'); continue; }
			string U = v[i] + string(k, '0'), V = v[i] + string(k, '9');
			if (v[i - 1] < U) { res += k; v[i] = U; continue; }
			if (v[i - 1] < V) { res += k; v[i] = addOne(v[i - 1]); continue; }
			res += k + 1; v[i] += string(k + 1, '0');
		}
		for (auto& x : v) cout << x << ' '; cout << '\n';
		cout << "Case #" << t << ": " << res << '\n';
	}
	cin.ignore(2); return 0;
}