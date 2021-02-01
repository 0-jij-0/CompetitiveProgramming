#include <iostream>
#include <string>
using namespace std;

string bin;

bool check(int i, int j) {
	for (int x = i; x <= j; x++) {
		for (int k = 1; x + 2*k <= j; k++) {
			int idx = x + 2 * k; int mid = x + k;
			if (bin[x] == bin[mid] && bin[x] == bin[idx]) { return true; }
		}
	}
	return false;
}

long long count() {
	long long ans = 0;
	for (unsigned int i = 0; i < bin.size(); i++) {
		unsigned int j = i + 2;
		for (; j < bin.size(); j++) {
			if (check(i, j)) { ans += bin.size() - j; break; }
		}
	}
	return ans;
}

int main() {
	cin >> bin;
	cout << count() << endl;
	return 0;
}