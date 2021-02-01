#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	bool res = true;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a = i != 0 && v[i - 1][j] == 'o';
			int b = i != n - 1 && v[i + 1][j] == 'o';
			int c = j != 0 && v[i][j - 1] == 'o';
			int d = j != n - 1 && v[i][j + 1] == 'o';
			if ((a + b + c + d) % 2) { res = false; break; }
		}
	cout << (res ? "YES" : "NO") << endl;
	cin.ignore(2); return 0;
}