#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SVSZ = 1000009;

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power of spf
int func[SVSZ];//Multiplicative Function
vector<int> primes;

//Assumes x is a power of a prime
int f(int x) { return x + 1; } //Modify accordingly

void buildSieveMult() { //Computes a multiplicative function
	spf[0] = spf[1] = 1;
	hpp[0] = 0; hpp[1] = 1;
	hpc[0] = hpc[1] = 0;
	func[0] = 0; func[1] = 1; //Initial values
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) {
			primes.push_back(i); spf[i] = i;
			func[i] = 2; hpp[i] = i; hpc[i] = 1;
		}
		for (int j = 0; j < (int)primes.size() && i * primes[j] < SVSZ; j++) {
			spf[i * primes[j]] = primes[j];
			if (i % primes[j]) {
				func[i * primes[j]] = func[i] * func[primes[j]];
				hpp[i * primes[j]] = primes[j]; hpc[i * primes[j]] = 1;
			}
			else {
				func[i * primes[j]] = func[i / hpp[i]] * f(1 + hpc[i]);
				hpp[i * primes[j]] = primes[j] * hpp[i];
				hpc[i * primes[j]] = 1 + hpc[i]; break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; buildSieveMult();
	while (n--) {
		int x; cin >> x; cout << func[x] << endl;
	}
}