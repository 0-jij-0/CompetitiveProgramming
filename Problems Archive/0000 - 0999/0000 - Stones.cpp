#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*int minIdx(int a[], int from, int to){

	int min = a[from];
	int idx = 0;
	for(int i = from; i <= to; i++){
		if(a[i] < min){	min = a[i];	idx = i; }
	}
	return idx;
}

void swap(int a[], int i, int j){
	int temp = a[i]; a[i] = a[j]; a[j] = temp;
}

void bubbleFromTo(int a[], int from, int to){
	
	int b = a[from];

	int i = 0;
	if(from < to){
		while (a[to] != b) { swap(a, from + i, from + i + 1); i++; }
	}
	else {
		while (a[to] != b) { swap(a, from - i, from - i - 1); i++; }
	}
}

int recMin(int a[], int n, int from, int to){
	
	if(from == to) { return 0;}

	int idx = minIdx(a, from, to);
	int i = idx - from;
	int j = to - idx;

	if(i < j){
		bubbleFromTo(a, idx, from);
		return i + recMin(a, n, from+1, to);
	}

	bubbleFromTo(a, idx, to);
	return j + recMin(a, n, from, to-1);
}

int main(){

	int m = 0; cin >> m;

	for (int k = 0; k < m; k++) {

		int n = 0;
		cout << "Enter the size of the array: "; cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++) { cin >> a[i]; }

		int count = recMin(a, n, 0, n - 1);
		cout << "minimum count = " << count << endl;
		for (int i = 0; i < n; i++) { cout << a[i] << " "; }
		cout << endl;	
	}

	cout << endl; cin.ignore(2); return 0;
}*/

vector<int> v;

int findMinOp(vector<int> &v, int l, int r) {
	if (r - l <= 1) { return 0; }
	int idx = min_element(v.begin() + l, v.begin() + r + 1) - v.begin();
	if (idx - l < r - idx) { 
		int s = idx - l;
		while (idx - 1 >= 0 && idx != l) { swap(v[idx], v[idx - 1]); idx--; }
		return s + findMinOp(v, l + 1, r);
	}
	int s = r - idx;
	while (idx + 1 != v.size() && idx != r) { swap(v[idx], v[idx + 1]); idx++; }
	return s + findMinOp(v, l, r - 1);
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		cout << findMinOp(v, 0, n - 1) << endl;
	}
	cin.ignore(2); return 0;
}