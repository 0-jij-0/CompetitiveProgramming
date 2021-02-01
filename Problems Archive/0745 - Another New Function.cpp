#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;
const int SVSZ = 2000002;

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int func[SVSZ];//Multiplicative Function
ll depth[SVSZ];
vector<int> primes;

//Assumes x is a power of a prime
int f(int x, int p) { return x - x / p; } //Modify accordingly

void buildSieveMult() { //Computes a multiplicative function
	spf[0] = spf[1] = 1;
	hpp[0] = 0; hpp[1] = 1;
	func[0] = 0; func[1] = 1; //Initial values
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) {
			primes.push_back(i); spf[i] = i;
			func[i] = f(i, i); hpp[i] = i;
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

	int t; cin >> t; buildSieveMult(); depth[1] = 0;
	for (int i = 2; i <= 2000000; i++)
		depth[i] = 1 + depth[func[i]];

	partial_sum(depth, depth + 2000002, depth);
	while (t--) {
		int m, n; cin >> m >> n;
		cout << depth[n] - depth[m - 1] << '\n';
	}
	cin.ignore(2); return 0;
}