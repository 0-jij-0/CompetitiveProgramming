#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
const int SVSZ = 100001;

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power Count of spf
ll func[SVSZ];//Multiplicative Function
vector<int> primes; int ONE = 1;

ll Mult(int HPP, int HPC, int SPF) { return 1ll - SPF; } //Modify accordingly

ll modInv(ll x) {
	ll res = 1, n = mod - 2;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

void buildSieveMult() { //Computes a multiplicative function over a range in O(n)
	spf[0] = spf[1] = hpp[1] = func[1] = 1; 
	hpp[0] = hpc[0] = hpc[1] = func[0] = 0;

	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { //i is Prime
			primes.push_back(i); spf[i] = i;
			func[i] = Mult(i, ONE, i); hpp[i] = i; hpc[i] = 1;
		}
		for (int j = 0; j < (int)primes.size() && i * primes[j] < SVSZ; j++) {
			spf[i * primes[j]] = primes[j];
			if (i % primes[j]) { //primes[j] < spf[i]
				func[i * primes[j]] = func[i] * func[primes[j]];
				hpp[i * primes[j]] = primes[j]; hpc[i * primes[j]] = 1;
			}
			else { //primes[j] == spf[i]
				hpp[i * primes[j]] = primes[j] * hpp[i]; hpc[i * primes[j]] = 1 + hpc[i];
				func[i * primes[j]] = func[i / hpp[i]] * Mult(hpp[i * primes[j]], hpc[i * primes[j]], primes[j]);
				break;
			}
		}
	}
}

vector<ll> freq, v;

int main() {
	freopen("lcm.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	buildSieveMult();
	int t; cin >> t; while (t--) {
		int n; cin >> n; freq.clear(); v.clear();
		freq.resize(SVSZ, 0); v.resize(SVSZ, 0);
		while (n--) { int x; cin >> x; freq[x]++; }

		ll res = 0;	for (int t = 1; t < SVSZ; t++) {
			for (int i = t; i < SVSZ; i += t)
				v[t] = (v[t] + freq[i] * i) % mod;
			v[t] = (v[t] * v[t]) % mod;
			v[t] = (v[t] * modInv(t)) % mod;
			res = (res + func[t] * v[t]) % mod;
		}
		cout << ((res % mod) + mod) % mod << '\n';
	}

	cin.ignore(2); return 0;
}