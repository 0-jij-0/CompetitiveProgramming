#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int SVSZ = 10000009;
typedef ll(*func_ptr) (int&, int&, int&);

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power Count of spf
ll func[SVSZ];//Multiplicative Function
vector<int> primes; int one = 1;

ll f(int &HPP, int &HPC, int &SPF) { 
	ll p = HPP; p *= p;
	return p - (p - 1) / (SPF + 1);
}

void buildSieveMult(func_ptr Mult) { //Computes a multiplicative function over a range in O(n)
	func[1] = spf[0] = spf[1] = hpp[1] = 1; //Initial Values
	func[0] = hpp[0] = hpc[0] = hpc[1] = 0; //Initial Values

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	buildSieveMult(f);
	int t; cin >> t; while (t--) {
		int n; cin >> n; cout << func[n] << '\n';
	}

	cin.ignore(2); return 0;
}