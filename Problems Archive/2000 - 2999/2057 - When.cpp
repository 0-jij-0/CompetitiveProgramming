#include <iostream>
using namespace std;

int main() {
	int k; cin >> k;
	if (k < 10) cout << "21:0" << k << '\n';
	else if (k < 60) cout << "21:" << k << '\n';
	else if (k < 70) cout << "22:0" << k - 60 << '\n';
	else cout << "22:" << k - 60 << '\n';
}