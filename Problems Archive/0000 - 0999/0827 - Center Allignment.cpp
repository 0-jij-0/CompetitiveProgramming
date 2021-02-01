#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s; vector<string> v; int n = 0, width = 0;
	while (getline(cin, s)) {
		v.push_back(s); n++;
		width = max(width, (int)s.size());
	}
	cout << string(width + 2, '*') << endl;
	int d = 0;
	for (int i = 0; i < n; i++) {
		int l = width - v[i].size();
		cout << "*" << string((l + d) / 2, ' ') << v[i];
		cout << string(l - (l + d) / 2, ' ') << '*' << endl;
		if (l % 2) { d = 1 - d; }
	}
	cout << string(width + 2, '*') << endl;
	cin.ignore(2); return 0;
}