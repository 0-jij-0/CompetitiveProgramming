#include <iostream>
#include <string>
using namespace std;

int freq[26];
bool check(string s) {
	for (unsigned int i = 1; i < s.size(); i++) {
		if (s[i] - s[i - 1] == 1) { return false; }
		if (s[i] - s[i - 1] == -1) { return false; }
	}
	return true;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		for (int i = 0; i < 26; i++) { freq[i] = 0; }
		string s; cin >> s;
		for (unsigned int j = 0; j < s.size(); j++) { freq[s[j] - 'a']++; }
		string even, odd;
		for (int j = 0; j < 25; j += 2) {
			while (freq[j] != 0) { freq[j]--; even.push_back(j + 'a'); }
		}
		for (int j = 1; j < 26; j += 2) {
			while (freq[j] != 0) { freq[j]--; odd.push_back(j + 'a'); }
		}
		bool b1 = check(even + odd);
		if (b1) { cout << even + odd << endl; continue; }
		b1 = check(odd + even);
		if (b1) { cout << odd + even << endl; continue; }
		cout << "No answer" << endl;
	}
	cin.ignore(2); return 0;
}