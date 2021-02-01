#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int e = 0, o = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a % 2) { o++; }
		else { e++; }
	}
	cout << min(e, o) << endl;
	cin.ignore(2); return 0;
}