#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string> a, b;

bool check(int i, int j) {
	if (i == j || (s[i] == '0' && i + 1 != j)) { return false; }
	for (int k = i; i < j; i++) {
		if (s[i] < '0' || s[i] > '9') { return false; }
	}
	return true;
}

int main() {
	cin >> s;
	int x = 0, y = 0;
	while (y != s.size()) {
		if (s[y] != ',' && s[y] != ';') { y++; continue; }
		bool ok = check(x, y);
		(ok ? a : b).push_back(string(s.begin() + x, s.begin() + y));
		x = y = y + 1;
	}
	bool ok = check(x, y);
	(ok ? a : b).push_back(string(s.begin() + x, s.begin() + y));
	if (!a.empty()) { cout << '"'; }
	else { cout << '-' << endl; }
	for (int i = 0; i < (int)a.size(); i++) {
		cout << a[i];
		if (i + 1 != (int)a.size()) { cout << ','; }
		else { cout << '"' << endl; }
	}
	if (!b.empty()) { cout << '"'; }
	else { cout << '-' << endl; }
	for (int i = 0; i < (int)b.size(); i++) {
		cout << b[i];
		if (i + 1 != (int)b.size()) { cout << ','; }
		else { cout << '"' << endl; }
	}
	cin.ignore(2); return 0;
}