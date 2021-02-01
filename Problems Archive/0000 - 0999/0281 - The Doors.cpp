#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int last0 = -1, last1 = -1;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 0) { last0 = i; }
		else { last1 = i; }
	}
	cout << min(last0, last1) + 1 << endl;
	cin.ignore(2); return 0;
}