#include <bits/stdc++.h>
using namespace std;

string s; int n; vector<string> res;

void move(int i, int j) {
	swap(s[i], s[j]); swap(s[i + 1], s[j + 1]); res.push_back(s);
}

void rearrange(string& s) {
	int last = s.find_last_of("."); if (last == n - 1) return;
	if (last < n - 2) { move(last - 1, n - 2); return; }
	move(0, last - 1); move(0, n - 2);
}

void step() {
	int b = s.find_first_of("B"), a = s.find_first_of("A", b + 2); 
	move(b, n - 2); move(a, b); if (a != n - 3) move(n - 2, a);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s; n <<= 1; rearrange(s);
	if (n < 6 || s == "ABAB.." || s == "BABA.."){
		int a = s.find_first_of("A"), b = s.find_first_of("B");
		cout << (a <= b && n != 6 ? "0" : "-1") << '\n'; return 0;
	}

	for (; s.find_first_of("B") < s.find_last_of("A"); step()) {
		int b = s.find_first_of("B"); if (s.substr(b, 4) == "BABB") {
			move(b, n - 2); move(b + 2, b); move(n - 2, b + 2);
		}
	} 

	cout << res.size() << '\n';
	for (auto& x : res) cout << x << '\n';
}