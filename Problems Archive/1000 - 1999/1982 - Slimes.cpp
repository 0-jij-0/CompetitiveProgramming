#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll a, b, k; cin >> a >> b >> k;
	int res = 0; while (a < b) { res++; a *= k; }
	cout << res << '\n';
	cin.ignore(2); return 0;
}