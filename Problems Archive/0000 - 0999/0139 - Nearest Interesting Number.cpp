#include <iostream>
using namespace std;

int sum_dig(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10; n /= 10;
	}
	return sum;
}

int main() {
	int a; cin >> a;
	while (true) {
		int s = sum_dig(a);
		if (s % 4 == 0) { cout << a << endl; break; }
		a++;
	}
	cin.ignore(2); return 0;
}