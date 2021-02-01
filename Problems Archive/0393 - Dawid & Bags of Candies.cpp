#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v; int sum = 0;

int main() {
	v.resize(4); for (auto &x : v) { cin >> x; sum += x; }
	sort(v.begin(), v.end());
	if (sum % 2) { cout << "NO" << endl; }
	else if (v.front() + v.back() == sum / 2) { cout << "YES" << endl; }
	else if (v.back() == sum / 2) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	cin.ignore(2); return 0;
}