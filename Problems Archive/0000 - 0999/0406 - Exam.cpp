#include <iostream>
#include <string>
using namespace std;

string a, b; int n;

int main() {
	int k; cin >> k >> a >> b; n = (int)a.size();
	int s = 0, d = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) { s++; }
		else { d++; }
	}
	int ans = 0;
	if (s >= k) { ans = k + d; }
	else { ans = s + (d - (k - s)); }
	cout << ans << endl;
	cin.ignore(2); return 0;
}