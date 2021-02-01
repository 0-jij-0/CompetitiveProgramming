#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> newChar;
string str; int k;

int main() {
	cin >> k >> str; int n = (int)str.size();
	vector<bool> v(26, 0);
	for (int i = 0; i < n; i++) {
		if (v[str[i] - 'a']) { continue; }
		newChar.push_back(i); v[str[i] - 'a'] = true;
	}
	if ((int)newChar.size() < k) { cout << "NO" << endl; return 0; }
	cout << "YES" << endl;
	for (int i = 0; i < k - 1; i++)
		cout << str.substr(newChar[i], newChar[i + 1] - newChar[i]) << endl;
	cout << str.substr(newChar[k - 1]) << endl;
	cin.ignore(2); return 0;
}