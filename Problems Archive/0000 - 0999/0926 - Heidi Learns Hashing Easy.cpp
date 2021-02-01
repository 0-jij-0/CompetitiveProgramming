#include <iostream>
using namespace std;

int main() {
	long long r; cin >> r;
	if (r % 2 == 0 || r < 4) { cout << "NO" << endl; }
	else { cout << 1 << ' ' << ((r - 3) >> 1) << endl; }
	cin.ignore(2); return 0;
}