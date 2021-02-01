#include <iostream>
using namespace std;

long long a, b, c;

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		cout << (a + b + c) / 2 << endl;
	}
	cin.ignore(2); return 0;
}