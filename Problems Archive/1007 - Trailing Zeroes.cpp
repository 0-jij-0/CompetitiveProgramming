#include <iostream>
using namespace std;

int main() {
	int n; cin >> n; int res = 0;
	while (n) { res += (n /= 5); }
	cout << res << endl;
	cin.ignore(2); return 0;
}