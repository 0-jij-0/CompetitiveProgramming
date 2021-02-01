#include <iostream>
using namespace std;
typedef long long ll;

ll knights(ll n) {
	return n * n * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cout << knights(i + 1) << '\n';
	cin.ignore(2); return 0;
}