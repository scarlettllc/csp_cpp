#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> b(n);
	int max_sum = 0, min_sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		max_sum += b[i];
	}
	vector<int> c(n);
	int i = n - 1;
	while (i >= 0) {
		int j = i - 1;
		c[i] = b[i];
		min_sum += c[i];
		while (j >= 0 && b[j] == b[i]) {
			c[j] = 0;
			--j;
		} 
		i = j;
	}
	cout << max_sum << endl;
	cout << min_sum << endl;
}