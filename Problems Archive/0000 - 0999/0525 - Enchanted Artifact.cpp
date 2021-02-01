#include <iostream>
#include <string>
using namespace std;

int main() {
	string sa(300, 'a'), sb(300, 'b');
	cout << sa << endl; int na; cin >> na;
	if (!na) { return 0; }
	cout << sb << endl; int nb; cin >> nb;
	if (!nb) { return 0; }
	na = 300 - na; nb = 300 - nb;
	int n = na + nb; string s(n, 'a');
	if (!nb) { cout << s << endl; cin >> n; return 0; }
	int prev = nb;
	for (int i = 0; i < n; i++) {
		s[i] = 'b'; cout << s << endl;
		int cur; cin >> cur;
		if (!cur) { return 0; }
		if (cur < prev) { prev = cur; }
		else { s[i] = 'a'; }
	}
	return 0;
}