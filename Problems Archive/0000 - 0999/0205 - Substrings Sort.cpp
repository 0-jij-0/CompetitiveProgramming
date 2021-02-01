#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string &a, string &b) {
	if (a.size() != b.size()) { return a.size() < b.size(); }
	return a < b;
}

vector<string> v;

bool check_subs(int i, int j) {
	string &s1 = v[i], &s2 = v[j];
	for (unsigned int i = 0; i < s2.size(); i++) {
		if (s2[i] == s1[0] && i + s1.size() <= s2.size()) {
			unsigned int j = 1;
			for (; j < s1.size(); j++) {
				if (s2[i + j] != s1[j]) { break; }
			}
			if (j == s1.size()) { return true; }
		}
	}
	return false;
}

void check() {
	for (unsigned int i = 1; i < v.size(); i++) {
		if (!check_subs(i - 1, i)) { cout << "NO" << endl; return; }
	}
	cout << "YES" << endl;
	for (auto &x : v) { cout << x << endl; }
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	sort(v.begin(), v.end(), compare);
	check();
	cin.ignore(2); return 0;
}
