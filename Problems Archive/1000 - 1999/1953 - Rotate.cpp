#include <iostream>
#include <string>
using namespace std;

int main() {
	char a; cin >> a; string A(1, a);
	char b; cin >> b; string B(1, b);
	char c; cin >> c; string C(1, c);

	cout << stoi(A + B + C) + stoi(B + C + A) + stoi(C + A + B) << '\n';
	cin.ignore(2); return 0;
}