#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s; int n;
vector<string> res;

bool splitOne(string &s, int p, int idx) {
	while (idx < n) { res.push_back(s.substr(idx, p)); idx += p; }
	return true;
}

bool splitTwo(string &s, int p, int q) {
	if (n % q == 0) { return splitOne(s, q, 0); }
	if (n % p == 0) { return splitOne(s, p, 0); }
	int i = 0;
	while (i < n) {
		if (n - i < p) { break; }
		res.push_back(s.substr(i, p)); i += p;
		if ((n - i) % q == 0) { return splitOne(s, q, i); }
	}
	return false;
}

int main() {
	int p, q; cin >> n >> p >> q >> s;
	if (!splitTwo(s, p, q)) { cout << -1 << endl; }
	else { cout << res.size() << endl; for (auto &x : res)cout << x << endl; }
	cin.ignore(2); return 0;
}