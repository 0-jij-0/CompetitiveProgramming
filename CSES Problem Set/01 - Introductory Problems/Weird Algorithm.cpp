#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n;
	for (; n != 1; n = n & 1 ? 3 * n + 1 : n >> 1)
		cout << n << ' '; cout << "1\n";
}