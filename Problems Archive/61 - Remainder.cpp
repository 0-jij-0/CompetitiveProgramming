#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, x, y; cin >> n >> x >> y;
	string s; cin >> s;

	int count = 0;
	for (int i = 0; i < y; i++) {
		if (s[s.size() - 1 - i] == '1') { count++; }
	}
	if (s[s.size() - 1 - y] == '0') { count++; }
	for (int i = y + 1; i < x; i++) {
		if (s[s.size() - 1 - i] == '1') { count++; }
	}
	cout << count << endl;
	return 0;
}

