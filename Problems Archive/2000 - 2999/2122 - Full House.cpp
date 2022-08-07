#include <iostream>
#include <algorithm>
using namespace std;

int a[5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	sort(a, a + 5);

	if (a[0] == a[1] && a[2] == a[4]) { cout << "Yes\n"; return 0; }
	if (a[3] == a[4] && a[2] == a[0]) { cout << "Yes\n"; return 0; }
	cout << "No\n";
}