#include <iostream>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; res += t / k;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}
