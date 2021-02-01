#include <iostream>
using namespace std;

int main() {
	int d, t, s; cin >> d >> t >> s;
	cout << (s*t >= d ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}