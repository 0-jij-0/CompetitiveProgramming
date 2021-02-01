#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, t;
vector<int> comp;
vector<char> letters;
int k;

string add(string &a, string &b) {
	string res(k, '0'); int c = 0;
	for (int i = k - 1; i >= 0; i--) {
		res[i] = 'a' + (a[i] + b[i] - 2 * 'a' + c) % 26;
		c = (a[i] + b[i] + c - 2 * 'a') / 26;
	}
	if (c != 0) { res.insert(res.begin(), 'b'); }
	return move(res);
}

string half(string &a) {
	string res; int i = 0, quo = 0;
	while (i < (int)a.size()) {
		quo *= 26; quo += (a[i] - 'a'); i++;
		while (i != (int)a.size() && quo < 2) { 
			res.push_back('a'); quo *= 26; quo += (a[i] - 'a'); i++;
		}
		res.push_back((quo / 2) + 'a'); quo %= 2;
	}
	if (res.size() > k) { res.erase(res.begin()); }
	while ((int)res.size() != k) { res.insert(res.begin(), 'a'); }
	return move(res);
}


int main() {
	cin >> k >> s >> t;
	string a = add(s, t);
	cout << half(a) << endl;
	cin.ignore(2); return 0;
}