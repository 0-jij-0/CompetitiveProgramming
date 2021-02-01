#include <iostream>
using namespace std;

int main() {
	int n, l, r; cin >> n >> l >> r;
	int min = n - l + (1 << l) - 1;
	int max = (1 << r) - 1 + (n - r)*(1 << (r - 1));
	cout << min << ' ' << max << endl;
	cin.ignore(2); return 0;
}