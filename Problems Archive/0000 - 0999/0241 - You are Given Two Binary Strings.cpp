#include <iostream>
#include <string>
using namespace std;

string s1, s2;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s1 >> s2; int j = s2.size() - 1;
		for (; j >= 0; j--) { if (s2[j] == '1') { break; } }
		j = s2.size() - j - 1;
		int k = s1.size() - j - 1;
		for (; k >= 0; k--) { if (s1[k] == '1') { break; } }
		k = s1.size() - k - 1;
		cout << k - j << endl;
	}
	cin.ignore(2); return 0;
}