#include <iostream>
using namespace std;

typedef long long ll;
ll n, s;

bool check(ll x) {
	ll sum = 0, X = x;
	while (X) { sum += X % 10; X /= 10; }
	return x - sum >= s;
}

ll find_num() {
	ll l = 0, r = n + 1;
	while (l != r) {
		ll mid = (l + r) / 2;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return n - l + 1;
}

int main() {
	cin >> n >> s;
	cout << find_num() << endl;
	cin.ignore(2); return 0;
}