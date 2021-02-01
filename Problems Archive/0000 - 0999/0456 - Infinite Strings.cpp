#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string to_baseb(unsigned long long x, int count, int b) {
	string res = "";
	while (x != 0) { res.push_back('a' + (x % b)); x /= b; }
	while ((int)res.size() != count) { res.push_back('a'); }
	reverse(res.begin(), res.end()); return move(res);
}

char find_char(unsigned long long k, int b) {
	int count = 1; unsigned long long len = b;
	while (k > len * count) {
		k -= len * count; count++; len *= b;
	}
	unsigned long long x = (k - 1) / count; int y = (k - 1) % count;
	string res = to_baseb(x, count, b);
	return res[y];
}

int main() {
	int T; cin >> T;
	while (T--) {
		int b; unsigned long long k; cin >> b >> k;
		if (b == 1) { cout << "a" << endl; }
		else { k++; cout << find_char(k, b) << endl; }
	}
	cin.ignore(2); return 0;
}