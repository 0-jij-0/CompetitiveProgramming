#include <iostream>
#include <string>
using namespace std;

int pow10[10];

int main() {
	pow10[0] = 1;
	for (int i = 1; i < 10; i++)
		pow10[i] = 10 * pow10[i - 1];

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int res = 0;
		while (n) {
			int s = to_string(n).size();
			res += pow10[s - 1];
			n -= pow10[s - 1] - (pow10[s - 1] / 10);
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}