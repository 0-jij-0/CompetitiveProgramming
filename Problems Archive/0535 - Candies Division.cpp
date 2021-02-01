#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int m = (n / k) * k + k / 2;
		cout << min(n, m) << endl;
	}
	cin.ignore(2); return 0;
}