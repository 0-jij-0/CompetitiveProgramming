#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
const int mod = 998244353;
const int SVSZ = 2000001;
typedef long long ll;
typedef int(*func_ptr) (int&, int&, int&);

vector<ll> dp(1000001, 0);

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power Count of spf
int func[SVSZ];//Multiplicative Function
vector<int> primes; int ONE = 1;

int divCount(int& HPP, int& HPC, int& SPF) { return HPC + 1; }

int f(int HPP, int HPC, int SPF) { return 0; } //Modify accordingly

void buildSieveMult(func_ptr Mult) { //Computes a multiplicative function over a range in O(n)
	spf[0] = spf[1] = hpp[1] = func[1] = 1; //Initial Values
	hpp[0] = hpc[0] = hpc[1] = func[0] = 0; //Initial Values

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


int main() {
	buildSieveMult(divCount);

	dp[0] = dp[1] = 1; int pref = 2;
	for (int i = 2; i < 1000001; i++) {
		int cur = i; while ((cur & 1) == 0) { cur >>= 1; }
		dp[i] = (pref + func[i << 1] - func[cur] - 1 + mod) % mod;
		pref = (pref + dp[i]) % mod;
	}
	int n; cin >> n; cout << dp[n] << '\n';
	cin.ignore(2); return 0;
}