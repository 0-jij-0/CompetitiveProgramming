#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> hero(n), villain(n);
	for (auto &x : hero) { cin >> x; }
	for (auto &x : villain) { cin >> x; }

	if (villain[0] < hero[0]) { cout << 0 << endl; return 0; }

	int res = villain[0] - hero[0]; bool OK = true;
	for (int i = 0; i < n; i++) {
		hero[i] += res;
		if (hero[i] < villain[i]) { OK = false; break; }
		else if (hero[i] > villain[i]) { break; }
	}

	cout << res + !OK << endl;
	cin.ignore(2); return 0;
}