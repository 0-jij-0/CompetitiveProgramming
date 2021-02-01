#include <iostream>
using namespace std;
typedef int (*func_ptr)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
func_ptr myF[3] = { add, sub, mul };

bool ok = false;

int exOp(func_ptr f[4], int a[5], int b[5]) {
	int a1 = f[0](a[b[0]], a[b[1]]);
	int a2 = f[1](a1, a[b[2]]);
	int a3 = f[2](a2, a[b[3]]);
	int a4 = f[3](a3, a[b[4]]);
	return a4;
}

void tryAllP(int i, func_ptr f[4], int a[5], int b[5], int v[5]) {
	if (i == 5) { ok = ok || exOp(f, a, b) == 23; return; }
	for(int j = 0; j < 5; j++)
		if (!v[j]) { v[j] = 1; b[i] = j; tryAllP(i + 1, f, a, b, v); v[j] = 0; }
}

void tryAllF(int i, func_ptr f[4], int a[5]) {
	if (i == 4) { int b[5], v[5] = { 0,0,0,0,0 }; tryAllP(0, f, a, b, v); return; }
	for (int j = 0; j < 3; j++) { f[i] = myF[j]; tryAllF(i + 1, f, a); }
}

int main() {
	int a[5]; cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	while (a[0] + a[1] + a[2] + a[3] + a[4] != 0) {
		func_ptr f[4]; tryAllF(0, f, a);
		cout << (ok ? "Possible" : "Impossible") << endl;
		cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]; ok = false;
	}
	cin.ignore(2); return 0;
}