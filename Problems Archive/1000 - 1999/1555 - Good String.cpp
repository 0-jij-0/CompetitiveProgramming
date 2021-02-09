#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	freopen("good.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k; cin >> s >> k; int n = (int)s.size();
	int i = 0, j = 0, cur = 0; char c = '0';
	while (j != n) {
		if (s[i] == s[j]) { cur++; j++; continue; }
		if (cur >= k) { c = s[i]; break; }
		i = j; cur = 0;
	}
	if (cur >= k) { c = s[i]; }
	if (c == '0') { cout << "NO" << '\n'; }
	else { cout << "YES " << c << '\n'; }
	cin.ignore(2); return 0;
}