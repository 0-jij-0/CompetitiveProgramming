#include <iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	int &mi = (a < b) ? a : b;
	int &ma = (a < b) ? b : a;
	cout << mi << ' ' << (ma - mi) / 2 << endl;
	cin.ignore(2); return 0;
}