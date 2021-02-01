#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b, t; cin >> a >> b >> t;
	string s = a + b;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	cout << (s == t ? "YES" : "NO") << endl;
	cin.ignore(2); return 0;
}