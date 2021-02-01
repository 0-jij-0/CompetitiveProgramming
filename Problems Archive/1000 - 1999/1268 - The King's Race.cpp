#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll n, x, y; cin >> n >> x >> y;
	ll X = n - x, Y = n - y;
	ll W = max(x - 1, y - 1), B = max(X, Y);
	cout << (W > B ? "Black" : "White") << '\n';
	cin.ignore(2); return 0;
}