#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon" };

string findEvolution(const string &s) {
	int n = (int)s.size();
	for (auto &x : v) {
		if (x.size() != n) { continue; }
		bool b = true;
		for (int i = 0; i < n; i++) {
			if (s[i] == '.') { continue; }
			if (s[i] != x[i]) { b = false; break; }
		}
		if (b) { return x; }
	}
	return "-1";
}

int main() {
	int n; string s; cin >> n >> s;
	cout << findEvolution(s) << endl;
	cin.ignore(2); return 0;
}