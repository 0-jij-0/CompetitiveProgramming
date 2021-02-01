#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<unsigned long long> max_a;
priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> min_b;
const unsigned long long mod = 998244353;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		unsigned long long x; cin >> x;
		x *= (long long) (i + 1ll)*(n - i);
		max_a.push(x);
	}
	for (int i = 0; i < n; i++) {
		unsigned long long x; cin >> x; min_b.push(x);
	}
	unsigned long long ans = 0;
	for (int i = 0; i < n; i++) {
		unsigned long long res = max_a.top() % mod;
		res = (res * min_b.top()) % mod;
		ans = (ans + res) % mod;
		max_a.pop(); min_b.pop();
	}
	cout << ans << endl;
	return 0;
}