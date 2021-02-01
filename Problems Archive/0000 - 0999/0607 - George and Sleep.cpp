#include <iostream>
#include <string>
using namespace std;

const int mod = 24 * 60;

int main() {
	string s, t; cin >> s >> t;
	int m = 60 * atoi(s.substr(0, 2).c_str()) + atoi(s.substr(3, 2).c_str());
	int d = 60 * atoi(t.substr(0, 2).c_str()) + atoi(t.substr(3, 2).c_str());
	m = (m - d + mod) % mod; int h = m / 60; m %= 60;
	string H = to_string(h); if (H.size() == 1) { H.insert(H.begin(), '0'); }
	string M = to_string(m); if (M.size() == 1) { M.insert(M.begin(), '0'); }
	cout << H + ":" + M << endl;
	cin.ignore(2); return 0;
}