#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n; cin >> n;
	int first, sum = 0, num = 0, res = 0;
	for (int i = 0; i < n; i++) {
		int d; cin >> d;
		if (num == 0) { num = 1; sum += d; continue; }
		if (d * num - sum >= 20) { res++; num = 1; sum = d; continue; }
		sum += d; num++;
	}
	cout << res + 1 << endl; cin.ignore(2); return 0;
}