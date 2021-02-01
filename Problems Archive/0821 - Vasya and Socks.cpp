#include <iostream>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int s = n + n / (m - 1);
	if (n % (m - 1) == 0) { s--; }
	cout << s << endl;
	cin.ignore(2); return 0;
}