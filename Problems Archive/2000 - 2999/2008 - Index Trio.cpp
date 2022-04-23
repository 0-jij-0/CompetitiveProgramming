#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<int, ll> freq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; while (n--) {
		int x; cin >> x; freq[x]++;
	}

	ll res = 0;
	for(int i = 1; i <= 200000; i++)
		for (int j = i; j <= 200000; j += i)
			res += freq[i] * freq[j] * freq[j / i];

	cout << res << '\n';
	cin.ignore(2); return 0;
}