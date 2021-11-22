#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int count_none_zeros(vector<int> a) {
	int result = 0, n = a.size(), i = 0;
	while (i < n) {
		if (a[i] != 0) {
			++result;
			while (i < n && a[i] != 0) {
				++i;
			}
		}
		else {
			++i;
		}
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int result = count_none_zeros(a);
	set<int> p_set(a.begin(), a.end());
	set<int>::iterator it;
	for (it = p_set.begin(); it != p_set.end(); ++it) {
		if (*it == 1) {
			continue;
		}
		vector<int> b(a.begin(), a.end());
		for (int i = 0; i < n; ++i) {
			if (b[i] < *it) {
				b[i] = 0;
			}
		}
		result = max(result, count_none_zeros(b));
	}
	cout << result;
}