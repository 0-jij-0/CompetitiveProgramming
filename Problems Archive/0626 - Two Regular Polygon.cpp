#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		cout << (n % m ? "NO" : "YES") << endl;
	}
	cin.ignore(2); return 0;
}