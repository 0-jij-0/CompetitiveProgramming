#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string b; cin >> b; int n = (int)b.size();
		string a(1, b.front());
		for (int i = 2; i < n; i += 2)
			a.push_back(b[i]);
		cout << a << b.back() << '\n';
	}
	cin.ignore(2); return 0;
}