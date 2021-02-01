#include <iostream>
#include <vector>
using namespace std;

vector<int> v, pos;

int main() {
	int n; cin >> n;
	v.resize(n); pos.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i]; v[i]--;
		pos[v[i]] = i;
	}
	long long res = 0;
	for (int i = 1; i < n; i++) 
		res += abs(pos[i] - pos[i - 1]);
	cout << res << endl;
	cin.ignore(2); return 0;
}