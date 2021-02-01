#include <iostream>
#include <string>
using namespace std;

bool checkPal(string s) { return s[0] == s[3] && s[1] == s[2]; }

string toString(int x) {
	if (x >= 10) { return move(to_string(x)); }
	string res = to_string(x);  res.insert(res.begin(), '0');
	return move(res);
}

int main() {
	int h, m; char c; cin >> h >> c >> m;
	while (true) {
		m++; if (m == 60) { h++; m = 0; if (h == 24) { h = 0; } }
		if (checkPal(toString(h) + toString(m))) { break; }
	}
	cout << toString(h) + ":" + toString(m) << endl;
	cin.ignore(2); return 0;
}