#include <iostream>
#include <map>
using namespace std;

map<int, int> freq;
long long sum = 0;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; sum += a; freq[a]++;
	}
	sum -= (long long)n*(n - 1) / 2;
	bool b = true, t = false; int prev = -2;
	if (freq[0] > 1) { b = false; goto RES; }
	for (auto &x : freq) {
		if (x.second > 2) { b = false; break; }
		if (x.second == 2 && t) { b = false; break; }
		if (prev == x.first - 1 && freq[prev] > 0 && x.second > 1) { b = false; break; }
		if (x.second == 2) { t = true; }
		prev = x.first;
	}
RES: if (b && sum % 2) { cout << "sjfnb" << endl; }
	 else { cout << "cslnb" << endl; }
	 cin.ignore(2); return 0;
}