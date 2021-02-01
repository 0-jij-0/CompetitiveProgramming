#include <iostream>
#include <string>
using namespace std;

string findMin(string s) {
	if (s.size() % 2) { return s; }
	int n = (int)s.size();
	string a = findMin(s.substr(0, n / 2));
	string b = findMin(s.substr(n / 2));
	return a < b ? a + b : b + a;
}

int main() {
	string a, b; cin >> a >> b;
	if (findMin(a) == findMin(b)) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	cin.ignore(2); return 0;
}