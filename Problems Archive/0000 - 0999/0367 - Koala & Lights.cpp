#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s; int n;
vector<int> a, b;

int update(int t) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (t < b[i]) { res += s[i] - '0'; continue; }
		if ((t - b[i]) % a[i]) { res += s[i] - '0'; continue; }
		s[i] = (s[i] == '0') ? '1' : '0'; res += s[i] - '0';
	}
	return res;
}

int main() {
	cin >> n >> s; 
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++) { cin >> a[i] >> b[i]; }
	int res = -1;
	for (int t = 0; t <= 10000; t++) {
		res = max(res, update(t));
		if (res == n) { break; }
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}