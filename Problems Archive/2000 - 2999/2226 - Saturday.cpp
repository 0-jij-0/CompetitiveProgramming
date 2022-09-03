#include <iostream>
#include <string>
#include <map>
#include <string>
using namespace std;

map<string, int> m = { {"Monday", 5}, {"Tuesday", 4}, {"Wednesday", 3}, {"Thursday", 2}, {"Friday", 1} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	cout << m[s] << '\n';
}