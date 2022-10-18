#include <bits/stdc++.h>
using namespace std;

const int D = 1001;
int t[D][D];

bool isPallindrome(string X, int i, int j) {
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}

	return true;
}

int Solve(string X, int i, int j) {
	if (t[i][j] != -1)
		return t[i][j];

	if (i >= j || isPallindrome(X, i, j)) {
		t[i][j] = 0;
		return 0;
	}

	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int left, right;
		if (t[i][k] == -1)
			left = Solve(X, i, k);
		else
			left = t[i][k];

		if (t[k + 1][j] == -1)
			right = Solve(X, k + 1, j);
		else
			right = t[k + 1][j];

		int temp_ans = left + right + 1;
		ans = min(ans, temp_ans);
	}

	return t[i][j] = ans;
}

int main() {
	string X; cin >> X;

	memset(t, -1, sizeof(t));

	cout << Solve(X, 0, X.length() - 1) << endl;
	return 0;
}
