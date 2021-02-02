#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> m = { {'R', 0}, {'L', 1}, {'B', 2} };
map<char, char> counter = { {'R', 'S'}, {'B', 'K'}, {'L', 'H'}, {'Z', 'C'} };
int c[3] = { 0, 0, 0 };

string mech(string &s) {
	string res(s.size(), '0');
	for (int i = 0; i < (int)s.size(); i++)
		res[i] = counter[s[i]];
	return move(res);
}

int main() {
	string s; cin >> s; string attack = ""; int n = (int)s.size();
	if (s.size() < 3) { cout << mech(s) << endl; return 0; }
	string res = ""; int i = 0, j = 0;
	while (j <= 2) { c[m[s[j++]]]++; } j--;
	while (j < n) {
		if (c[0] && c[1] && c[2]) {
			attack.push_back('Z');
			if (n - j - 1 < 3) { attack += s.substr(j + 1); break; }
			i = j = j + 1; c[0] = c[1] = c[2] = 0;
			while (j - i <= 2) { c[m[s[j++]]]++; }
			j--; continue;
		}
		if (j == n - 1) { attack += s.substr(i); break; }
		attack.push_back(s[i]);
		c[m[s[i++]]]--;	c[m[s[++j]]]++;
	}
	
	cout << mech(attack) << endl;
	cin.ignore(2); return 0;
}