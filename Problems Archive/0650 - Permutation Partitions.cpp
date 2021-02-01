#include <iostream>
#include <vector>
using namespace std;

vector<int> p;
const long long mod = 998244353;

int main() {
	int n, k; cin >> n >> k; p.resize(n);
	for (auto &x : p) { cin >> x; }
	int req = n - k; vector<int> idx;
	for (int i = 0; i < n; i++)
		if (p[i] > req) idx.push_back(i);

	long long res = p[idx[0]], count = 1;
	for (int i = 1; i < (int) idx.size(); i++) {
		res += p[idx[i]]; count *= (idx[i] - idx[i - 1]); count %= mod;
	}
	cout << res << ' ' << count << endl;
	cin.ignore(2); return 0;
}