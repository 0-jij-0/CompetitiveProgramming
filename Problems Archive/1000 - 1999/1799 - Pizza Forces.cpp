#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll n; cin >> n; ll rem = n % 6;
		if (n < 6) { cout << "15\n"; continue; }
		ll req = (n / 6 - 1) * 15;
		if (rem == 0) { req += 15; }
		else if (rem < 3) { req += 20; }
		else if (rem < 5) { req += 25; }
		else { req += 30; }
		cout << req << '\n';
	}
	cin.ignore(2); return 0;
}