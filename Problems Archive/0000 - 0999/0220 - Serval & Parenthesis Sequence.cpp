#include <iostream>
#include <vector>
using namespace std;

vector<char> v;

int main() {
	int n; cin >> n;
	int op = 0;
	for (int i = 0; i < n; i++) {
		char c; cin >> c; v.push_back(c);
		if (c == '(') { op++; }
	}
	int pre = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] != '?') { continue; }
		if (op < n / 2) { v[i] = '('; op++; }
		else { v[i] = ')'; }
	}
	pre = 0; bool b = true;
	for (int i = 0; i < n; i++) {
		if (v[i] == '(') { pre++; }
		else { pre--; }
		if (pre < 0) { b = false; break; }
		if (pre == 0 && i + 1 != n) { b = false; break; }
	}
	if (pre != 0) { b = false; }
	if (b) { for (auto &x : v) { cout << x; } }
	else { cout << ":("; }
	cout << endl; cin.ignore(2); return 0;
}