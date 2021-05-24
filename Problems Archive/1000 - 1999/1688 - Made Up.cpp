#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> a, b, c;
vector<ll> freqA, freqC;

int main() {
	int n; cin >> n; a.resize(n);
	b.resize(n); c.resize(n);
	freqA.resize(n, 0); freqC.resize(n, 0);

	for (auto& x : a) { cin >> x; freqA[--x]++;; }
	for (auto& x : b) { cin >> x; x--; }
	for (auto& x : c) { cin >> x; freqC[b[--x]]++; }

	ll res = 0; for (int i = 0; i < n; i++)
		res += freqA[i] * freqC[i];

	cout << res << '\n';
	cin.ignore(2); return 0;
}