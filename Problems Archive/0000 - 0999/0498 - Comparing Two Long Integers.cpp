#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a, b;

int compare(string &a, string &b) {
	if (a.size() != b.size())
		return (a.size() < b.size()) ? -1 : 1;

	while (!a.empty()) {
		if (a.back() < b.back()) { return -1; }
		else if (a.back() > b.back()) { return 1; }
		a.pop_back(); b.pop_back();
	}
	return 0;
}

int main() {
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (!a.empty() && a.back() == '0') { a.pop_back(); }
	while (!b.empty() && b.back() == '0') { b.pop_back(); }

	int x = compare(a, b);
	if (x == -1) { cout << '<' << endl; }
	else if (!x) { cout << '=' << endl; }
	else { cout << '>' << endl; }
	cin.ignore(2); return 0;
}