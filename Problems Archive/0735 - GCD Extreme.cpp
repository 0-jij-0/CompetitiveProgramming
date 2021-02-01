#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;
const int SVSZ = 1000009;

ll spf[SVSZ]; //Smallest Prime Factor
ll hpp[SVSZ]; //Highest Power of spf
ll func[SVSZ];//Multiplicative Function
vector<int> primes;

//Assumes x is a power of a prime
ll f(ll x, ll p) { return x - x / p; } //Modify accordingly

void buildSieveMult() { //Computes a multiplicative function
	spf[0] = spf[1] = 1;
	hpp[0] = 0; hpp[1] = 1;
	func[0] = 0; func[1] = 1; //Initial values
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) {
			primes.push_back(i); spf[i] = i;
			func[i] = i - 1; hpp[i] = i;
		}
		for (int j = 0; j < (int)primes.size() && i * primes[j] < SVSZ; j++) {
			spf[i * primes[j]] = primes[j];
			if (i % primes[j]) {
				func[i * primes[j]] = func[i] * func[primes[j]];
				hpp[i * primes[j]] = primes[j];
			}
			else {
				func[i * primes[j]] = func[i / hpp[i]] * f(hpp[i] * primes[j], primes[j]);
				hpp[i * primes[j]] = primes[j] * hpp[i]; break;
			}
		}
	}
}

vector<ll> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	buildSieveMult(); res.resize(1000001, 0);
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 2*i; j <= 1000000; j += i) {
			res[j] += func[j / i] * i;
		}
	}
	partial_sum(res.begin(), res.end(), res.begin());
	int n; cin >> n;
	while (n) { cout << res[n] << '\n'; cin >> n; }
	cin.ignore(2); return 0;
}