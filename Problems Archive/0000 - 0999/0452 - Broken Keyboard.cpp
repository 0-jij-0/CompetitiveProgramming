#include <iostream>
#include <string>
#include <set>
using namespace std;

string s; set<char> res;

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> s; int n = (int)s.size(); res.clear();
		for (int i = 0; i < n; i++) {
			int count = 0; char c = s[i]; 
			while (i < n && s[i] == c) { count++; i++; }
			if (count % 2) { res.insert(c); }
			i--;
		}
		for (auto &c : res) { cout << c; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}