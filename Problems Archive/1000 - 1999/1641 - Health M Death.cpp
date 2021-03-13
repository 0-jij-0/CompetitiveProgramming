#include <iostream>
using namespace std;

int main() {
	int m, h; cin >> m >> h;
	cout << (h % m ? "No" : "Yes") << '\n';
	cin.ignore(2); return 0;
}