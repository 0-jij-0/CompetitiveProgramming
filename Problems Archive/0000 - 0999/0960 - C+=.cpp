#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> fib;

void fillFib() {
	fib.push_back(1); fib.push_back(1);
	while (fib.back() < 1000 * 1000 * 1000)
		fib.push_back(fib[(int)fib.size() - 1] + fib[(int)fib.size() - 2]);
}

int main() {
	int t; cin >> t; fillFib(); int N = (int)fib.size();
	while (t--) {
		int a, b, n; cin >> a >> b >> n;
		if (a > b) { swap(a, b); }
		if (b > n) { cout << 0 << '\n'; continue; }
		int l = 1, r = N - 1;
		while (l != r) {
			int mid = (l + r) >> 1;
			bool c = (fib[mid] * b + fib[mid - 1] * a) > n;
			c ? r = mid : l = mid + 1;
		}
		cout << l << '\n';
	}
	cin.ignore(2); return 0;
}