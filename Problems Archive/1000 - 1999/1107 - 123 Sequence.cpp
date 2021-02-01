#include <iostream>
#include <algorithm>
using namespace std;

int a[4];

int main() {
	int n; cin >> n; while (n--) {
		int x; cin >> x; a[x]++;
	}
	cout << min({ a[1] + a[2], a[2] + a[3], a[1] + a[3] });
}