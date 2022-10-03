#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const ld PI = acos(-1);

void FFT(vector<complex<ld>>& a, bool inverse) {
	int n = (int)a.size(); //Assumes n is a power of 2
	for (int i = 1, j = 0; i < n; i++) { //Sorting by reverse bits
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) j ^= bit;
		if (i < (j ^= bit)) swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		ld O = 2 * PI / len * (inverse ? -1 : 1);
		complex<ld> Wn(cos(O), sin(O));
		for (int i = 0; i < n; i += len) {
			complex<ld> W(1);
			for (int j = 0; j < (len >> 1); j++, W *= Wn) {
				complex<ld> even = a[i + j], odd = W * a[i + j + (len >> 1)];
				a[i + j] = even + odd; a[i + j + (len >> 1)] = even - odd;
			}
		}
	}

	if (inverse) for (auto& x : a) x /= n;
}

vector<ll> polyMult(vector<int>& a, vector<int>& b) {
	vector<complex<ld>> A(a.begin(), a.end()), B(b.begin(), b.end());
	int N = (int)a.size(), M = (int)b.size();
	int n = 1; while (n < (N + M)) { n <<= 1; }
	A.resize(n, 0); B.resize(n, 0);

	FFT(A, false); FFT(B, false);
	for (int i = 0; i < n; i++) A[i] *= B[i];

	FFT(A, true); vector<ll> res(n);
	for (int i = 0; i < n; i++)
		res[i] = (ll)round(A[i].real());

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}