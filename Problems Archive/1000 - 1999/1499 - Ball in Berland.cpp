#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> A, B;
vector<int> freqA, freqB;

int main() {
	int t; cin >> t; while (t--) {
		int a, b, k; cin >> a >> b >> k;
		A.resize(k); freqA.clear(); freqA.resize(a, 0);
		B.resize(k); freqB.clear(); freqB.resize(b, 0);
		for (auto& x : A) { cin >> x; freqA[--x]++; }
		for (auto& x : B) { cin >> x; freqB[--x]++; }

		ll res = 0; for (int i = 0; i < k; i++)
			res += k + 1 - freqA[A[i]] - freqB[B[i]];

		cout << (res >> 1) << '\n';
	}
	cin.ignore(2); return 0;
}