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

vector<ll> polyMult(vector<ll>& a, vector<ll>& b) {
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
vector<int> v; string s;
vector<ll> freq, revFreq;

ll zeroSubstrings() {
	int n = (int)s.size(); ll res = 0;
	for (int i = 0, j = 0; j < n; j++) {
		if (s[j] == '1') { i = j; i++; continue; }
		res += j - i + 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; int n = (int)s.size();
	for (char c : s) v.push_back(c == '1');
	partial_sum(v.begin(), v.end(), v.begin());

	freq.resize(n + 1); freq[0] = 1; for (auto& x : v) freq[x]++;
	revFreq = freq; reverse(revFreq.begin(), revFreq.end());

	vector<ll> res = polyMult(freq, revFreq);
	cout << zeroSubstrings() << ' ';
	for (int i = n + 1; i <= (n << 1); i++)
		cout << res[i] << ' '; cout << '\n';
}