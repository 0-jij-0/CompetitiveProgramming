#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int k; cin >> k; v.resize(k + 1);
	for (int i = 1; i <= k; i++)
		v[i] = k / i;

	ll res = 0;
	for (int i = 1; i <= k; i++)
		for (int j = i; j <= k; j += i)
			res += v[j];

	cout << res << '\n';
	cin.ignore(2); return 0;
}