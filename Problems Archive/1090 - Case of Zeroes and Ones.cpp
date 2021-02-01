#include <iostream>
using namespace std;

int main() {
	int n; cin >> n; int z = 0, o = 0;
	while (n--) { char c; cin >> c; (c == '0' ? z : o)++; }
	if (z > o) { swap(z, o); }
	cout << o - z << endl;
	cin.ignore(2); return 0;
}