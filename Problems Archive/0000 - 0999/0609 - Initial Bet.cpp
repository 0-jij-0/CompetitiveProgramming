#include <iostream>
using namespace std;

int main() {
	int sum = 0; int x = 5;
	while (x--) { int a; cin >> a; sum += a; }
	cout << (sum % 5 || !sum ? -1 : sum / 5) << endl;
	cin.ignore(2); return 0;
}