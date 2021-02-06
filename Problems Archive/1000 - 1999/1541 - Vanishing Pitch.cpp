#include <iostream>
using namespace std;

int main() {
	int v, t, s, d; cin >> v >> t >> s >> d;
	cout << (d <= (s * v) && d >= (t * v) ? "No" : "Yes") << '\n';
	cin.ignore(2); return 0;
}