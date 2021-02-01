#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person {
	long long a, b;
	person() {}
	person(long long _a, long long _b) :
		a(_a), b(_b) {}

	bool operator <(const person &rhs)const {
		return (b - a) < (rhs.b - rhs.a);
	}
};

vector<person> people;

int main() {
	int n; cin >> n; people.resize(n);
	for (int i = 0; i < n; i++) {
		long long a, b; cin >> a >> b;
		person p(a, b); people[i] = p;
	}
	sort(people.begin(), people.end());
	long long diss = 0;
	for (unsigned int i = 0; i < people.size(); i++) {
		person &p = people[i];
		diss += p.a*i + p.b*(n - i - 1);
	}
	cout << diss << endl;
	cin.ignore(2); return 0;
}