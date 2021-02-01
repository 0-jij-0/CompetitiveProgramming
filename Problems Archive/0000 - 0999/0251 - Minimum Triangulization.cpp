#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int res = 0, i = 2;
	while (i < n) { res += i * (i + 1); i++; }
	cout << res << endl;
	cin.ignore(2); return 0;
}