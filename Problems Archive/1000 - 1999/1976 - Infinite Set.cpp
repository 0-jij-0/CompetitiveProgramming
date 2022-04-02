#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

unordered_set<int> st;
vector<int> v, fib(200001, 1);

bool check(int x) {
	if (x == 0) { return true; }
	if (st.count(x)) { return false; }
	if (x & 1) return check((x ^ 1) >> 1);
	return (x & 2) || check(x >> 2);
}

inline int countBits(int x) {
	int res = 0; 
	while (x) { res++; x >>= 1; }
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 2; i <= 200000; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;

	for (int i = 1; i <= 200000; i++)
		fib[i] = (fib[i] + fib[i - 1]) % mod;

	int n, p; cin >> n >> p; v.resize(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());

	for (auto& x : v) if (check(x)) st.insert(x);

	int res = 0; for (auto& x : st) {
		int b = countBits(x);
		if (b <= p) res = (res + fib[p - b]) % mod;
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}