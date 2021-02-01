#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int SVSZ = 100009;

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int totient[SVSZ];//Euler Totient Function
vector<int> primes;

void buildSieve() {
	spf[0] = spf[1] = 1;
	hpp[0] = 0; hpp[1] = 1;
	totient[0] = 0; totient[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { 
			primes.push_back(i); spf[i] = i;
			totient[i] = i - 1; hpp[i] = i;
		}
		for (int j = 0; j < (int)primes.size() && i * primes[j] < SVSZ; j++) {
			spf[i * primes[j]] = primes[j];
			if (i % primes[j]) {
				totient[i * primes[j]] = totient[i] * totient[primes[j]];
				hpp[i * primes[j]] = primes[j];
			}
			else {
				totient[i * primes[j]] = totient[i / hpp[i]] * (hpp[i] * primes[j] - hpp[i]);
				hpp[i * primes[j]] = primes[j] * hpp[i]; break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; buildSieve();
	while (t--) {
		int n; cin >> n; ll res = 0;
		for (int i = 1; i <= n; i++) { res += totient[i]; }
		cout << res * res << '\n';
	}
	cin.ignore(2); return 0;
}