#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n; int m = n;
	int d = 0; while (m) { d++; m /= 10; }
	int digCount = 1; ll mult = 1, res = 0;
	while (digCount < d) { res += 9 * mult*digCount; digCount++; mult *= 10; }
	cout << res + digCount * (n - mult + 1) << endl;
	cin.ignore(2); return 0;
}