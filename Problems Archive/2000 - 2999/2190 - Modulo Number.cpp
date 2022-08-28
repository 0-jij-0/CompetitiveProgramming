#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;
	cout << ((n % mod) + mod) % mod << '\n';
}