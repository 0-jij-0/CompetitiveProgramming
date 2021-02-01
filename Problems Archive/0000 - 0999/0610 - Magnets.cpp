#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	string prev = "00"; int res = 0;
	while (n--) {
		string a; cin >> a;
		if (a == prev) { continue; }
		prev = a; res++;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}