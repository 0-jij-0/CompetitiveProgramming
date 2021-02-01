#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int SVSZ = 10000005;

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
ll func[SVSZ];//Multiplicative Function

//Assumes x is a power of a prime
int f(int x, int p) { return x - x / p; } //Modify accordingly

void buildSieveMult() { //Computes a multiplicative function
	spf[0] = spf[1] = 1;
	hpp[0] = 0; hpp[1] = 1;
	func[0] = 0; func[1] = 1; //Initial values
	vector<int> primes;
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

bool checkPerm(int n1, int n2) {
	int cnt[10] = { 0,0,0,0,0,0,0,0,0,0 };
	while (n1) { cnt[n1 % 10]++; n1 /= 10; }
	while (n2) { cnt[n2 % 10]--; n2 /= 10; }
	for (int i = 0; i < 10; i++)
		if (cnt[i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; buildSieveMult();
	vector<ll> res(10000001, 0); ll cur = 0;
	for (ll i = 21; i <= 10000000; i++) {
		if (!checkPerm(i, func[i])) { res[i] = cur; continue; }
		if ((cur * func[i]) >= (i * func[cur])) { cur = res[i] = i; }
		else { res[i] = cur; }
	}
	while (t--) { 
		int n; cin >> n; n--;
		if (n >= 21) { cout << res[n] << '\n'; }
		else { cout << "No solution." << '\n'; }
	}
	cin.ignore(2); return 0;
}