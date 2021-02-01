#include <iostream>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	if (n == 1) { cout << 1 << endl; return 0; }
	int a = m - 1, b = m + 1;
	cout << (n - b + 1 > a ? b : a) << endl;
	cin.ignore(2); return 0;
}