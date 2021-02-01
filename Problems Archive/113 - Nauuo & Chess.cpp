#include <iostream>
using namespace std;

void find_min(int k) {
	int m = (k / 2) + 1;
	cout << m << endl;
	for (int i = 1; i <= m; i++) {
		cout << 1 << " " << i << endl; k--;
	}
	for (int i = 2; k != 0; i++) {
		cout << m << " " << i << endl; k--;
	}
}

int main() {
	int k; cin >> k;
	find_min(k);
	cin.ignore(2); return 0;
}