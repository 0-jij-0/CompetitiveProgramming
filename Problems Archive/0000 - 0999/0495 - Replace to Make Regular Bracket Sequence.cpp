#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <map>
using namespace std;

set<char> open = { '<', '{', '[', '(' };
map<char, char> m = { {'<', '>'}, {'{', '}'}, {'[', ']'}, {'(', ')'} };
stack<char> s; string bs;

int main() {
	cin >> bs; int pref = 0;
	for (char &c : bs) {
		if (open.count(c)) { pref++; }
		else { pref--; }
		if (pref < 0) {
			cout << "Impossible" << endl;
			cin.ignore(2); return 0;
		}
	}
	if (pref) {
		cout << "Impossible" << endl;
		cin.ignore(2); return 0;
	}
	int res = 0;
	for (char &c : bs) {
		if (open.count(c)) { s.push(c); continue; }
		else if (m[s.top()] == c) { s.pop(); continue; }
		res++; s.pop();
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}