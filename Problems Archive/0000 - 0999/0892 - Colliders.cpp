#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int SVSZ = 100009;
typedef void (*func_ptr)(int);

int spf[SVSZ]; //Smallest Prime Factor
int taken[SVSZ];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

void addQuery(int n) {
	if (n == 1) {
		if (taken[1]) { cout << "Already on" << '\n'; return; }
		cout << "Success" << '\n'; taken[1] = 1; return;
	}
	vector<int> pf; int m = n;
	while (m != 1) {
		int s = spf[m]; pf.push_back(s);
		if (taken[s] == n) { cout << "Already on" << '\n'; return; }
		if (taken[s]) { cout << "Conflict with " << taken[s] << '\n'; return; }
		while (m % s == 0) { m /= s; }
	}
	cout << "Success" << '\n';
	for (auto &x : pf) { taken[x] = n; }
}

void removeQuery(int n) {
	if (n == 1) {
		if (!taken[1]) { cout << "Already off" << '\n'; return; }
		cout << "Success" << '\n'; taken[1] = 0; return;
	}
	vector<int> pf; int m = n;
	while (m != 1) {
		int s = spf[m]; pf.push_back(s);
		if (taken[s] != n) { cout << "Already off" << '\n'; return; }
		while (m % s == 0) { m /= s; }
	}
	cout << "Success" << '\n';
	for (auto &x : pf) { taken[x] = 0; }
}

func_ptr query[2] = { addQuery, removeQuery };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; buildSieve(); 
	memset(taken, 0, sizeof(taken));

	while (m--) {
		char c; int x; cin >> c >> x;
		query[c == '-'](x);
	}

	cin.ignore(2); return 0;
}