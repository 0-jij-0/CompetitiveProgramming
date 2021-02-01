#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> vowelly;

int check(int n) {
	int s = (int)floor(sqrt(n));
	int div = 0;
	for (int i = s; i >= 5; i--) {
		if (n % i == 0) { div = i; break; }
	}
	if (div == 0) { return -1; }
	return div;
}

void build(int k) {
	int n = check(k);
	if (n == -1) { cout << -1 << endl; return; }
	int m = k / n;
	string s = "aeiou";
	while (s.size() < n) { s.push_back('z'); }
	string res = "";

	int x = 0, y = n-1;
	for (int i = 0; i < m; i++) {
		for (int j = x; true; j++) {
			j %= n;
			res.push_back(s[j]);
			if (j == y) { break; }
		}
		x++; x %= n;
		y++; y %= n;
	}
	cout << res << endl;
}

int main() {
	int k; cin >> k;
	build(k);
	return 0;
}