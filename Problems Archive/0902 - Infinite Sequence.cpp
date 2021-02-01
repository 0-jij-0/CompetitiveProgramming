#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n; ll i = 0;
	while (n > i) { n -= i++; }
	cout << n << endl; cin.ignore(2); return 0;
}