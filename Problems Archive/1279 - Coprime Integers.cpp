#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SVSZ = 10000001;
typedef int(*func_ptr) (int&, int&, int&);

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power Count of spf
int func[SVSZ];//Multiplicative Function
vector<int> primes; int one = 1;

int mobius(int &HPP, int &HPC, int &SPF) { return (HPC == 0) - (HPC == 1); }

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

ll count(ll a, ll b) { //relatively prime pairs 1 <= x <= a and 1 <= y <= b
	ll res = 0; for (int i = 1; i <= min(a, b); i++)
		res += (a / i) * (b / i) * func[i];
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	buildSieveMult(mobius);
	int a, b, c, d; cin >> a >> b >> c >> d;
	ll bd = count(b, d), ac = count(a - 1, c - 1);
	ll ad = count(a - 1, d), bc = count(b, c - 1);

	cout << (bd + ac) - (ad + bc) << '\n';

	cin.ignore(2); return 0;
}