#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int main() {
	int n1, n2; cin >> n1 >> n2;
 
	int ans;
	if (n2 > n1) {
		ans = n2 - n1;
		if (360 - n2 + n1 < ans) {
			ans = -(360 - n2 + n1);
		}
	}
	else { 
		ans = n1 - n2;
		if (360 - n1 + n2 < ans) {
			ans = 360 - n1 + n2;
		}
		else { ans = -ans; }
	}
 
	if (ans == -180) { ans = 180; }
	cout << ans << endl;
}