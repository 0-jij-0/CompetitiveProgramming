#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int partials[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
vector<int> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s >> s; stringstream ss(s);
		int m, d; char c; ss >> m >> c >> d;
		m--; v[i] = partials[m] + d;
	}
	sort(v.begin(), v.end()); int oct27 = partials[9] + 27;
	int max_dif = v.front() - v.back() + 365, max_idx = 0;
	for (int i = 1; i < n; i++) {
		int dif = v[i] - v[i - 1];
		if (dif > max_dif) { max_dif = dif; max_idx = i; }
		else if (dif == max_dif) {
			int d1 = v[i] - oct27 - 1; if (d1 <= 0) { d1 += 365; }
			int d2 = v[max_idx] - oct27 - 1; if (d2 <= 0) { d2 += 365; }
			if (d1 < d2){ max_dif = dif; max_idx = i; }
		}
	}
	int day = v[max_idx], month = 0;
	day--; if (day == 0) { day += 365; }
	for (; month < 12; month++) {
		if (day > months[month]) { day -= months[month]; }
		else { month++; break; }
	}
	if (month < 10) { cout << 0 << month << '-'; }
	else { cout << month << '-'; }
	if (day < 10) { cout << 0 << day << endl; }
	else { cout << day << endl; }
	cin.ignore(2); return 0;
}