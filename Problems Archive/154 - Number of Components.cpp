#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;

long long count_comp(int &n) {
	long long a = v[0];
	long long res = v[0] * (n - v[0] + 1);
	for (int i = 1; i < n; i++) {
		long long b = a; a = v[i];
		if (a < b) { res += a * (b - a); }
		else { res += (a - b)*(n - a + 1); }
	}
	return res;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; }
	cout << count_comp(n) << endl;
	cin.ignore(2); return 0;
}