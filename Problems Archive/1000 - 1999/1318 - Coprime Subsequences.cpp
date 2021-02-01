#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int SVSZ = 100001;
const ll mod = 1000 * 1000 * 1000 + 7;
typedef int(*func_ptr) (int&, int&, int&);

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power Count of spf
int func[SVSZ];//Multiplicative Function
vector<int> primes; int one = 1;

int mobius(int &HPP, int &HPC, int &SPF) { return (HPC == 0) - (HPC == 1); }

int f(int HPP, int HPC, int SPF) { return 0; } //Modify accordingly

void buildSieveMult(func_ptr Mult) { //Computes a multiplicative function over a range in O(n)
	spf[0] = spf[1] = hpp[1] = func[1] = 1; //Initial Values
	hpp[0] = hpc[0] = hpc[1] = func[0] = 0; //Initial Values

	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { //i is Prime
			primes.push_back(i); spf[i] = i;
			func[i] = Mult(i, one, i); hpp[i] = i; hpc[i] = 1;
		}
		for (int j = 0; j < (int)primes.size() && i * primes[j] < SVSZ; j++) {
			spf[i * primes[j]] = primes[j];
			if (i % primes[j]) { //primes[j] < spf[i]
				func[i * primes[j]] = func[i] * func[primes[j]];
				hpp[i * primes[j]] = primes[j]; hpc[i*primes[j]] = 1;
			}
			else { //primes[j] == spf[i]
				hpp[i * primes[j]] = primes[j] * hpp[i]; hpc[i * primes[j]] = 1 + hpc[i];
				func[i * primes[j]] = func[i / hpp[i]] * Mult(hpp[i * primes[j]], hpc[i * primes[j]], primes[j]);
				break;
			}
		}
	}
}

vector<int> cnt(SVSZ, 0);

void getDivisorsHelper(int i, int curr, vector<pair<int, int>> &v) {
	if (i == (int)v.size()) { cnt[curr]++; return; }
	getDivisorsHelper(i + 1, curr, v);
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first;
		getDivisorsHelper(i + 1, curr, v);
	}
}

void getDivisors(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int d = spf[x], c = 0;
		while (x % d == 0) { x /= d; c++; }
		v.push_back({ d, c });
	}
	getDivisorsHelper(0, 1, v);
}

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x*x) % mod)
		if (n & 1)res = (res * x) % mod;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	buildSieveMult(mobius);
	int n; cin >> n; while (n--) {
		int x; cin >> x; getDivisors(x);
	}

	ll res = 0; for (int i = 1; i < SVSZ; i++)
		res = (res + mod + (power(2, cnt[i]) - 1) * func[i]) % mod;

	cout << res << '\n'; cin.ignore(2); return 0;
}