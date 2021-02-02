#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n, d, k; cin >> n >> d >> k;
	vector<pair<int, string>> employees(n);
	for (int i = 0; i < n; i++) {
		string name; int salary;
		cin >> name >> salary;
		employees[i] = { salary, name };
	}

	long long remove = 0;
	sort(employees.rbegin(), employees.rend());
	for (int i = 0; i < k; i++) {
		remove += employees[i].first;
	}

	if (remove < d) { cout << "impossible" << endl; return 0; }

	cout << k << endl;
	for (int i = 0; i < k; i++) {
		cout << employees[i].second << ", YOU ARE FIRED!" << endl;
	}

	cin.ignore(2); return 0;
}