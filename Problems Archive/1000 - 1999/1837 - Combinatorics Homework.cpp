#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int a, b, c, m; cin >> a >> b >> c >> m;
		int same = max(0, a - 1) + max(0, b - 1) + max(0, c - 1);
		if (same < m) { cout << "NO\n"; continue; }
		//if ((same + m) & 1) { cout << "NO\n"; continue; }
		int arr[3] = { a, b, c }; sort(arr, arr + 3);
		int mi = max(0, arr[2] - arr[1] - arr[0] - 1);
		if (m < mi) { cout << "NO\n"; continue; }
		cout << "YES\n";
	}
	cin.ignore(2); return 0;
}