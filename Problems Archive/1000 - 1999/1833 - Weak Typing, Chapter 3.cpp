#include <fstream>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

string s;

void processDot(ll& res, ll& curL, ll& curR, ll& numP, ll& n, ll& first, ll& last, bool fO, bool lO) {
	res = (res << 1) % mod;
	ll leftExt = (curL * n) % mod;
	ll rightExt = (curR * n) % mod;
	res = (res + leftExt + rightExt) % mod;

	curL = (curL << 1) % mod; curR = (curR << 1) % mod;
	curL = (curL + n * numP) % mod; curR = (curR + n * numP) % mod;
	numP = (numP << 1) % mod;

	if (fO ^ lO) {
		ll L = (last + 1) % mod, R = (n - first + mod) % mod;
		curL = (curL + L) % mod; curR = (curR + R) % mod;
		ll newPair = (L * R) % mod;
		res = (res + newPair) % mod; 
		numP = (numP + 1) % mod;
	}

	last = (last + n) % mod; n = (n << 1) % mod;
}

void processF(ll& res, ll& curL, ll& curR, ll& numP, ll& n) {
	res = (res + curL) % mod; 
	n = (n + 1) % mod;
	curR = (curR + numP) % mod;
}

void processOX(ll& res, ll& curL, ll& curR, ll& numP, ll& n, ll& first, ll& last, bool &fO, bool &lO, char c) {
	res = (res + curL) % mod; 
	curR = (curR + numP) % mod;
	if (first == -1) { fO = lO = (c == 'O'); first = last = n; }

	if ((lO ^ (c == 'O')) && last != -1) {
		res = (res + last + 1) % mod;
		curL = (curL + last + 1) % mod;
		curR = (curR + 1) % mod;
		numP = (numP + 1) % mod;
	}

	last = n; lO = c == 'O';
	n = (n + 1) % mod;
}

int main() {
	ifstream cin("A3.in.txt");
	ofstream cout("A3.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int k; cin >> k >> s; ll res = 0;
		
		ll curLeft = 0, curRight = 0, numPairs = 0, n = 0; 
		bool fO = 0, lO = 0; ll first = -1, last = -1;

		for (char& c : s) {
			if (c == '.') {	processDot(res, curLeft, curRight, numPairs, n, first, last, fO, lO); }
			else if (c == 'F') { processF(res, curLeft, curRight, numPairs, n); }
			else { processOX(res, curLeft, curRight, numPairs, n, first, last, fO, lO, c); }			
		}

		cout << "Case #" << t << ": " << res << '\n';
	}

	cin.ignore(2); return 0;
}