#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s; int n;
long long prod9[10];

long long find_max(int i, int m) {
	if (i == n) { return 1; }
	long long a = m * find_max(i + 1, s[i + 1] - '0');
	long long b = prod9[n - i - 1];
	if (m != 1 || i != 0) { b *= m - 1; }
	return max(a, b);
}

int main() {
	prod9[0] = 1ll; for (int i = 1; i < 10; i++) { prod9[i] = prod9[i - 1] * 9ll; }
	cin >> s; n = (int) s.size(); s.push_back(0);
	cout << find_max(0, s[0] - '0') << endl;
	cin.ignore(2); return 0;
}