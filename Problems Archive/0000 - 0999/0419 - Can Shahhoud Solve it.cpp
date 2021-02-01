#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int s, d; cin >> s >> d;
		cout << ((s >= d) ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}