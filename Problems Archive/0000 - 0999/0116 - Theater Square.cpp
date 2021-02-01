#include <iostream>
using namespace std;

int main() {
	int n, m, a; cin >> n >> m >> a;
	long long v = (n + a - 1) / a;
	long long h = (m + a - 1) / a;
	cout << v * h << endl;
	cin.ignore(2); return 0;
}