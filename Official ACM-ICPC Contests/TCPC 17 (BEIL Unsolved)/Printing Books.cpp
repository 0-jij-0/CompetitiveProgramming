#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		long long n, x;	cin >> x >> n;
		int s = to_string(n).size();
		long long dec = (long long)(pow(10, s) - n) * s;
		long long top = 0;
		while (dec <= x) {
			top += dec / s;	x -= dec; s++;
			dec = s * 9 * pow(10, (s - 1));
		}
		if (x % s) { cout << -1 << endl; }
		else { cout << top + (x / s) << endl; }
	}
	cin.ignore(2); return 0;
}