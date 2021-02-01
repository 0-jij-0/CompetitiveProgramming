#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	double res = 0.0;
	while (n != 0) {
		res += (1.0 / (double)n);
		n--;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}