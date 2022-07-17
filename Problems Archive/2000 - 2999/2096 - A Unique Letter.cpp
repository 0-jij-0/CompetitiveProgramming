#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	sort(s.begin(), s.end());

	if (s[0] != s[1]) { cout << s[0] << '\n'; }
	else if (s[1] != s[2]) { cout << s[2] << '\n'; }
	else { cout << -1 << '\n'; }
}