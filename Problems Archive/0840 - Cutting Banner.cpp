#include <iostream>
#include <string>
using namespace std;

string s; int n;
const string res = "CODEFORCES";

string query(int i, int j) {
	if (i == 0) { return move(s.substr(j + 1)); }
	if (j == n - 1) { return move(s.substr(0, i)); }
	return move(s.substr(0, i) + s.substr(j + 1));
}

bool check(string &s) {
	int k = n - 10;
	if (n < 10) { return false; }
	if (n == 10) { return s == res; }
	for (int i = 0; i <= n - k; i++)
		if (query(i, i + k - 1) == res)
			return true;
	return false;
}

int main() {
	cin >> s; n = (int)s.size();
	bool b = check(s);
	cout << (b ? "YES" : "NO") << endl;
	cin.ignore(2); return 0;
}