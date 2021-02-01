#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s; cin >> s; int n = (int)s.size();
	vector<int> a, b; int i = 0, j = n - 1;
	while (i < j) {
		if (s[i] == ')') { i++; continue; }
		if (s[j] == '(') { j--; continue; }
		a.push_back(i++); b.push_back(j--);
	}
	reverse(b.begin(), b.end());
	if (a.empty()) { cout << 0 << endl; return 0; }
	cout << 1 << endl << a.size() + b.size() << endl;
	for (auto &x : a) { cout << x + 1 << ' '; }
	for (auto &x : b) { cout << x + 1 << ' '; }
	cin.ignore(2); return 0;
}