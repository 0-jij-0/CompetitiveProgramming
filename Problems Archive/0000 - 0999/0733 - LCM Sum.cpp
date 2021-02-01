#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int SVSZ = 1000009;

ll spf[SVSZ]; //Smallest Prime Factor
ll hpp[SVSZ]; //Highest Power of spf
ll func[SVSZ];//Multiplicative Function
vector<int> primes;

//Assumes x is a power of a p(prime)
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t; buildSieveMult();
	while (t--) {
		int n; cin >> n; ll res = -1; int i;
		for (i = 1; i * i < n; i++) {
			if (n % i) { continue; }
			res += func[i] * i + func[n / i] * (n / i);
		}
		if (i * i == n) { res += func[i] * i; }
		cout << ((res * n) / 2) + n << '\n';
	}
	cin.ignore(2); return 0;
}