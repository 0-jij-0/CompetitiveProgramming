#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SVSZ = 10000001;
typedef ll(*func_ptr) (int&, int&, int&);

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power Count of spf
ll func[SVSZ];//Multiplicative Function
vector<int> primes; int ONE = 1;

ll divSum(int& HPP, int& HPC, int& SPF) { 
	ll h = HPP, s = SPF;
	return (h * s - 1) / (s - 1);
}

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
				func[i * primes[j]] = (ll)func[i] * (ll)func[primes[j]];
				hpp[i * primes[j]] = primes[j]; hpc[i * primes[j]] = 1;
			}
			else { //primes[j] == spf[i]
				hpp[i * primes[j]] = primes[j] * hpp[i]; hpc[i * primes[j]] = 1 + hpc[i];
				func[i * primes[j]] = (ll)func[i / hpp[i]] * Mult(hpp[i * primes[j]], hpc[i * primes[j]], primes[j]);
				break;
			}
		}
	}
}

vector<int> res(10000001, -1);

int main() {
	buildSieveMult(divSum);
	for (int i = 1; i < SVSZ; i++) {
		if (func[i] > 10000000) { continue; }
		if (res[func[i]] != -1) { continue; }
		res[func[i]] = i;
	}
	int t; cin >> t; while (t--) {
		int c; cin >> c; cout << res[c] << '\n';
	}
	cin.ignore(2); return 0;
}