#include <iostream>
using namespace std;

int main() {
	int q; cin >> q;
	while (q--) {
		long long n, m; cin >> n >> m; n /= m;
		int pat_len = 0; long long pat_sum = 0;
		int i = 0;
		for (int j = 0; j < 10; j++) {
			pat_sum += i; i = (i + m) % 10;
		}
		long long res = pat_sum * (n / 10);
		int rem = n % 10; i = 0;
		for (int j = 0; j <= rem; j++) {
			res += i; i = (i + m) % 10;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}