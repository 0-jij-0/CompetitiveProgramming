#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
long long mod = 1000 * 1000 * 1000 + 7;
vector<int> v;
long long fib[100001];

void fill_fib() {
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 100001; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
}

int main() {
	fill_fib();
	cin >> s; int n = (int)s.size();
	long long res = 1; bool b = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'm' || s[i] == 'w') { b = false; break; }
		if (s[i] != 'u' && s[i] != 'n') { continue; }
		int a = 0; char c = s[i];
		while (i < n && s[i] == c) { a++; i++; }
		if (a > 1) { v.push_back(a); }
		i--;
	}
	if (!b) { cout << 0 << endl; cin.ignore(2); return 0; }
	for (auto &x : v) { res *= fib[x]; res %= mod; }
	cout << res << endl;
	cin.ignore(2); return 0;
}