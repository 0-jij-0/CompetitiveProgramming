#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
vector<long long> dv;

int main() {
	cin >> s; dv.resize(s.size(), 0ll);
	for (unsigned int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1] && s[i] == 'v') { dv[i] = 1ll; }
	}
	for (unsigned int i = 1; i < s.size(); i++) {
		dv[i] = dv[i - 1] + dv[i];
	}
	long long count = 0; 
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == 'o') { count += dv[i] * (dv.back() - dv[i]); }
	}
	cout << count << endl;
	cin.ignore(2); return 0;
}