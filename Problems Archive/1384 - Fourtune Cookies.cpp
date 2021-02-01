#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[4]; cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a, a + 4);
	if (a[3] == a[0] + a[1] + a[2]) { cout << "Yes" << '\n'; }
	else if (a[3] + a[0] == a[1] + a[2]) { cout << "Yes" << '\n'; }
	else { cout << "No" << '\n'; }
	cin.ignore(2); return 0;
}