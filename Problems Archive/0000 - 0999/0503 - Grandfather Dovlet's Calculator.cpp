#include <iostream>
using namespace std;

int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

inline int count(int n) {
	int res = 0;
	while (n) { res += a[n % 10]; n /= 10; }
	return res;
}

int main() {
	int a, b; cin >> a >> b;
	int res = 0;
	for (int i = a; i <= b; i++)
		res += count(i);
	cout << res << endl;
	cin.ignore(2); return 0;
}