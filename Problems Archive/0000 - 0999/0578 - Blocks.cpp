#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> res;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	
	for (char &c : s)
		c = (c == 'B') ? '0' : '1';

	bool inv = false;
	for (int i = 1; i < n; i++) {
		char c = (s[i] - '0' + inv) % 2 + '0';
		if (c == s[0]) { inv = false; continue; }
		res.push_back(i + 1); inv = true;
	}
	if (!inv) { 
		cout << res.size() << endl;
		for (auto &x : res) { cout << x << ' '; }
		cout << endl; cin.ignore(2); return 0;
	}
	inv = true; res.clear(); res.push_back(1);
	for (int i = 1; i < n; i++) {
		char c = (s[i] - '0' + inv) % 2 + '0';
		if (c != s[0]) { inv = false; continue; }
		res.push_back(i + 1); inv = true;
	}
	if (!inv) {
		cout << res.size() << endl;
		for (auto &x : res) { cout << x << ' '; }
		cout << endl; cin.ignore(2); return 0;
	}
	cout << -1 << endl; cin.ignore(2); return 0;
}

