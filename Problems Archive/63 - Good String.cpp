#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

void good() {
	if (s.size() < 2) { cout << s.size() << endl << endl; return; }
	vector<bool> print;	print.resize(s.size(), 1);
	int count = 0;
	for (int i = 0; i < s.size() - 1; i += 2) {
		if (s[i] != s[i + 1]) { continue; }
		print[i] = 0; i--; count++;
	}
	if ((s.size() - count) % 2 == 1) { print[s.size() - 1] = 0; count++; }
	cout << count << endl;
	for (int i = 0; i < s.size(); i++) {
		if (print[i] == true) { cout << s[i]; }
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	cin >> s;
	good();
	return 0;
}
