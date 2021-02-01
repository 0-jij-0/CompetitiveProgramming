#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> res;
string str1, str2; int n;

void fill_res() {
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) {
			if (j == i) { continue; }
			for (int k = 0; k < 3; k++) {
				if (k == j || k == i) { continue; }
				string s1(n, 'a' + i);	string s2(n, 'a' + j);
				string s3(n, 'a' + k);
				string s4; s4.push_back('a' + i);
				s4.push_back('a' + j); s4.push_back('a' + k);
				res.push_back(s1 + s2 + s3);
				string s5; while ((int)s5.size() != 3 * n) { s5 += s4; }
				res.push_back(s5);
			}
		}
}

bool check(string &s) {
	for (int i = 0; i < (int)s.size() - 1; i++) {
		char c1 = s[i], c2 = s[i + 1];
		string c; c.push_back(c1); c.push_back(c2);
		if (c == str1 || c == str2) { return false; }
	}
	return true;
}

int main() {
	cin >> n >> str1 >> str2; fill_res(); cout << "YES" << endl;
	for (auto &x : res) { if (check(x)) { cout << x << endl; break; } }
	cin.ignore(2); return 0;
}



