#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("dahab.in", "r", stdin);
	int n; cin >> n;
	cout << to_string(n).size() << '\n';
	cin.ignore(2); return 0;
}