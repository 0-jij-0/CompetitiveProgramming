#include <iostream>
#include <algorithm>
using namespace std;

int a[3];

int main() {
	cin >> a[0] >> a[1] >> a[2]; sort(a, a + 3);

	cout << (a[1] - a[0] == a[2] - a[1] ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}