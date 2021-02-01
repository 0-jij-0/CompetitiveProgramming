#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t, p;
int pc[26];

bool check() {
	unsigned int i = 0, j = 0, size = s.size();
	for (; j < s.size(); i++) {
		if (i >= t.size()) { return false; }
		int idx = t[i] - 'a';
		if (idx == s[j] - 'a') { j++; continue; }
		if (pc[idx] == 0) { return false; }
		pc[idx]--; size++;
	}

	for (; size < t.size(); i++) {
		int idx = t[i] - 'a';
		if (pc[idx] == 0) { return false; }
		pc[idx]--; size++;
	}
	return true;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 26; j++) { pc[j] = 0; }
		cin >> s >> t >> p;
		for (unsigned int j = 0; j < p.size(); j++) { pc[p[j] - 'a']++; }
		string res = (check()) ? "YES" : "NO";
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}