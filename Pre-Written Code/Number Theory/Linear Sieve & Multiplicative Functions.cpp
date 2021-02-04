#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int SVSZ = 100009;
typedef int(*func_ptr) (int&, int&, int&);

int spf[SVSZ]; //Smallest Prime Factor
int hpp[SVSZ]; //Highest Power of spf
int hpc[SVSZ]; //Highest Power Count of spf
int func[SVSZ];//Multiplicative Function
vector<int> primes; int ONE = 1;

int identity(int &HPP, int &HPC, int &SPF) { return HPP; }
int divCount(int &HPP, int &HPC, int &SPF) { return HPC + 1; }
int divSum(int &HPP, int &HPC, int &SPF) { return (HPP * SPF - 1) / (SPF - 1); }
int eulerTot(int &HPP, int &HPC, int &SPF) { return HPP - HPP / SPF; }
int mobius(int &HPP, int &HPC, int &SPF) { return (HPC == 0) - (HPC == 1); }

int f(int HPP, int HPC, int SPF) { return 0; } //Modify accordingly

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

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll euler_phi(int n, vector<pair<int, int>> &v) {
	ll res = n;
	for (auto &x : v) { res -= res / x.first; }
	return res;
}

int divisor_function(int n, vector<pair<int, int>> &v) {
	int res = 1;
	for (auto &x : v) { res *= x.second + 1; }
	return res;
}

void getDivisorsHelper(int i, int curr, vector<pair<int, int>> &v) {
	if (i == (int)v.size()) { return; }
	getDivisorsHelper(i + 1, curr, v);
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first;
		getDivisorsHelper(i + 1, curr, v);
	}
}

void getDivisors(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		v.push_back({ d, cnt });
	}
	getDivisorsHelper(0, 1, v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}