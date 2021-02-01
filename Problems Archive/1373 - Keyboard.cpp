#include <iostream>
using namespace std;

int main() {
	char S, T; cin >> S >> T;
	char r = (S == 'Y') ? T + 'A' - 'a' : T;
	cout << r << '\n';
	cin.ignore(2); return 0;
}