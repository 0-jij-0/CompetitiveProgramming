#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(2 * n);
	int i = 0, j = n - 1, k = 1;
	while (i < j) { v[i++] = v[j--] = k; k += 2; }
	i = n, j = 2 * n - 2, k = 2;
	while (i < j) { v[i++] = v[j--] = k; k += 2; }
	if (n % 2) { v[2 * n - 1] = v[n / 2] = n; }
	else { v[2 * n - 1] = v[n - 1 + n/2] = n; }
	for (auto &x : v) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}