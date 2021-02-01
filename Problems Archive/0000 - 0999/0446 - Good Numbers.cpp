#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string tobase3(long long n) {
	string res = "";
	while (n != 0) { res.push_back((n % 3) +'0'); n /= 3; }
	reverse(res.begin(), res.end());
	return move(res);
}

long long tobase10(string &s) {
	long long res = 0;
	for (auto &c : s) {	res *= 3; res += c - '0'; }
	return res;
}

int main() {
	int q; cin >> q;
	while (q--) {
		long long n; cin >> n;
		string s = tobase3(n);
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] != '2') { continue; }
			int j = i - 1;
			for (; j >= 0; j--) { 
				if (s[j] == '0') { break; }
				else { s[j] = '0'; }
			}
			if (j != -1) { s[j] = '1'; }
			else { s.insert(s.begin(), '1'); i++; }
			for (; i < (int)s.size(); i++) { s[i] = '0'; }
			break;
		}
		cout << tobase10(s) << endl;
	}
	cin.ignore(2); return 0;
}