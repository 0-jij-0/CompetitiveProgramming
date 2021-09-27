#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	int n; cin >> n; v.resize(n); ll sum = 0;
	for (auto& x : v) { cin >> x; sum += x; }
	ll X; cin >> X; ll k = (X / sum) * n; X %= sum;
	int i = 0; while (X >= 0) { X -= v[i++]; k++; }
	cout << k << '\n';
	cin.ignore(2); return 0;
}