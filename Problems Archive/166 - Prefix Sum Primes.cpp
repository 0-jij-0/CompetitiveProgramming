#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
int freq[3];

void build_sieve(int n) {
	vector<int> spf; spf.resize(n + 1, 0);
	spf[0] = spf[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (spf[i] == 0) {
			primes.push_back(i);
			spf[i] = i;
		}
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] <= n; ++j) {
			spf[i * primes[j]] = primes[j];
		}
	}
}

void build_array(int &n) {
	vector<int> res; int i = 0; int sum = 0;
	while (res.size() != n) {
		int x = primes[i] - sum;
		int num2 = x / 2;
		if (num2 <= freq[2]) {
			freq[2] -= num2; sum += 2 * num2;
			while (num2 > 0) { res.push_back(2); num2--; }
			if (x % 2) {
				if (freq[1] != 0) { sum++; freq[1]--; res.push_back(1); }
			}
			i++; continue;
		}
		else {
			sum += 2 * freq[2];
			while (freq[2] > 0) { res.push_back(2); num2--; freq[2]--; }
			int num1 = 2 * num2; if (x % 2) { num1++; }
			if (num1 <= freq[1]) {
				freq[1] -= num1; sum += num1;
				while (num1 > 0) { res.push_back(1); num1--; }
				i++; continue;
			}
			else { 
				sum += freq[1];
				while (freq[1] > 0) { res.push_back(1); freq[1]--; }
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i];
		if (i + 1 == n) { cout << endl; }
		else { cout << ' '; }
	}
}

int main() {
	int n; cin >> n;
	build_sieve(3 * n);
	freq[1] = freq[2] = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; freq[a]++;
	}
	build_array(n);
	cin.ignore(2); return 0;
}