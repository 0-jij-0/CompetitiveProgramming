#include <iostream>
#include <string>
using namespace std;

string s1, s2;

bool equivalent(int &l1, int &r1, int &l2, int &r2) {
	if (s1.substr(l1, r1 - l1 + 1) == s2.substr(l2, r2 - l2 + 1)) { return true; }
	int mid1 = (l1 + r1) / 2, mid2 = (l2 + r2) / 2;
	int mid1_ = mid1 + 1, mid2_ = mid2 + 1;
	bool b1 = equivalent(l1, mid1, l2, mid2) && equivalent(mid1_, r1, mid2_, r2);
	if (b1) { return true; }
	b1 = equivalent(l1, mid1, mid2_, r2) && equivalent(mid1_, r1, l2, mid2);
	if (b1) { return true; }
	return false;
}

int main() {

}