#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int SVSZ = 1000001;
typedef int(*func_ptr) (int&, int&, int&);

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power Count of spf
int func[SVSZ];//Multiplicative Function
vector<int> primes; int ONE = 1;

int squareFree(int& HPP, int& HPC, int& SPF) { return (HPC & 1 ? SPF : 1); }

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
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	buildSieveMult(squareFree); 
	int t; cin >> t; while (t--) {
		int n; cin >> n; vector<int> v(n);
		for (auto& x : v) { cin >> x; x = func[x]; }
		map<int, int> m; for (auto& x : v) m[x]++;
		//for (auto& x : v) cout << x << ' '; cout << '\n';

		int zero = 0, one = 0; for (auto& x : m) {
			zero = max(zero, x.second);
			if (x.second % 2 == 0) one += x.second;
		}

		if (m[1] % 2) { one += m[1]; }
		int ans[2] = { zero, max(zero, one) };
		int q; cin >> q; while (q--) {
			ll w; cin >> w; cout << ans[w != 0] << '\n';
		}
	}
	cin.ignore(2); return 0;
}