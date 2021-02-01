#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> ciphertext;

bool compare(const string &a, const string &b) {
	bool b3 = a.size() < b.size();
	if (b3) { return true; }
	bool b1 = a.size() == b.size();
	bool b2 = a < b;
	return b1 && b2;
}

struct compareString {
	bool operator()(const string &a, const string &b) const {
		bool b3 = a.size() < b.size();
		if (b3) { return true; }
		bool b1 = a.size() == b.size();
		bool b2 = a < b;
		return b1 && b2;
	}
};

string subtract(const string &lhs, const string &rhs) {

	bool less = compare(lhs, rhs);
	int n; string str1, str2;
	if (less) { str1 = rhs; str2 = lhs; n = rhs.size(); }
	else { str1 = lhs; str2 = rhs; n = lhs.size(); }

	while (str2.size() != n) { str2 = "0" + str2; }
	int carry = 0; string res(n, '0');

	for (int i = 0; i < n; i++) {
		int idx = n - 1 - i;
		char r = '0'  + str1[idx] - str2[idx] - carry;
		if (r < '0') { res[idx] = r + 10; carry = 1; }
		else { res[idx] = r; carry = 0; }
	}

	while (res[0] == '0') { res.erase(res.begin()); }
	if (res.empty()) { res = "0"; }
	if (less) { return "-" + res; }
	return res;
}

string longDivision(string &number, string &divisor, string &mod_res) {
	string ans = ""; unsigned int idx = 0; string temp = "";
	while (compare(temp, divisor) && idx < number.size()) {
		temp.push_back(number[idx]); idx++;
	}

	while (true) {
		char count = '0';
		while (compare(divisor, temp) || divisor == temp) {
			temp = subtract(temp, divisor); count++;
		}
		ans += count;
		if (idx != number.size()) {
			temp.push_back(number[idx]); idx++;
		}
		while (!temp.empty() && temp[0] == '0') { temp.erase(temp.begin()); }
		if (temp.empty()) { temp = "0"; }
		if (idx == number.size() && compare(temp, divisor)) { break; }
	}
	mod_res = temp;
	if (ans.length() == 0) { return "0"; }
	return ans;
}

string gcd(string &a, string &b) {
	if (compare(a, b)) { return gcd(b, a); }
	if (b == "0") { return a; }
	string mod_res;
	string temp = longDivision(a, b, mod_res);
	return gcd(b, mod_res);
}

string cryptopangrams() {
	int same = 0;
	while (ciphertext[same + 1] == ciphertext[same]) { same++; }
	string mod_res;
	string g = gcd(ciphertext[same], ciphertext[same+1]);

	string temp = longDivision(ciphertext[same + 1], g, mod_res);
	ciphertext[same + 1] = g;
	for (int i = same; i >= 0; i--) { 
		ciphertext[i] = longDivision(ciphertext[i], g, mod_res);
		g = ciphertext[i];
	}
	g = temp;
	for (unsigned int i = same + 2; i < ciphertext.size(); i++) {
		string temp = ciphertext[i];
		ciphertext[i] = g;
		g = longDivision(temp, ciphertext[i], mod_res);
	}
	ciphertext.push_back(g);

	map<string, char, compareString> letters;
	for (int i = 0; letters.size() != 26; i++) {
		pair<string, char> p(ciphertext[i], 0); letters.insert(p);
	}

	map<string, char, compareString>::iterator it = letters.begin();
	int i = 0;
	for (; it != letters.end(); it++) {
		it->second = 'A' + i; i++;
	}

	string res = "";
	for (unsigned int i = 0; i < ciphertext.size(); i++) {
		res.push_back(letters[ciphertext[i]]);
	}
	return res;
}

int main() {

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, l; cin >> n >> l;
		ciphertext.clear(); ciphertext.resize(l);
		for (int i = 0; i < l; i++) {
			cin >> ciphertext[i];
		}
		cout << "Case #" << i + 1 << ": " << cryptopangrams() << endl;
	}
	cout << endl; cin.ignore(2); return 0;
}