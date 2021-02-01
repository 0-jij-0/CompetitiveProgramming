#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

int main() {
	int n; cin >> n; ll factN = 1, twoN = 1;
	for (int i = 1; i <= n; i++) factN = (factN * i) % mod;
	for (int i = 0; i < n - 1; i++) twoN = (twoN << 1) % mod;

	cout << (factN - twoN + mod) % mod << endl;
	cin.ignore(2); return 0;
}