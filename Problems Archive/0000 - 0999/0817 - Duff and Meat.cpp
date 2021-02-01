#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, p;

int main() {
	int n; cin >> n; a.resize(n); p.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> p[i];
	int minPrice = 200, res = 0;
	for (int i = 0; i < n; i++) {
		minPrice = min(minPrice, p[i]);
		res += a[i] * minPrice;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}