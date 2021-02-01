#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> a;

int makeThemEqual() {
	map<int, int> numbers;
	for (int i = 0; i < a.size(); i++) {
		numbers[a[i]] = a[i];
	}
	if (numbers.size() > 3) { return -1; }
	if (numbers.size() == 1) { return 0; }
	map<int, int>::iterator it = numbers.begin();
	int a = it->first; it++;
	int b = it->first; it++;
	if (numbers.size() == 2) {
		int res = b - a;
		if (res % 2 == 0) { return res / 2; }
		return res;
	}
	int c = it->first;
	if (c - b == b - a) { return b - a; }
	return -1;
}

int main() {
	int n; cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << makeThemEqual() << endl;
	return 0;
}