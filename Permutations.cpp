#include <stdio.h>
#include <stdlib.h>

int outputCount;

void print(int arr[], int x, int n) {
	int sum = 0;

	for (int i = 0; i < x; i++) {
		sum += (arr[i] * i);
	}
	if (sum <= n) {
		outputCount++;
		for (int i = 0; i < x; i++) {
			printf("%d", arr[i]);
		}
		printf("\n");
	}
}

void permuteUtil(int arr[], int x, int n, int st) {
	if (st == x - 1) {
		print(arr, x, n);
		return;
	}
	int tmp;

	for (int i = st; i < x; i++) {
		tmp = arr[st];
		arr[st] = arr[i];
		arr[i] = tmp;
		permuteUtil(arr, x, n, st + 1);

		//swapping again to get the original array in "for" loop
		tmp = arr[st];
		arr[st] = arr[i];
		arr[i] = tmp;
	}
}

void xpermute(int x, int n) {
	int * arr = (int *)malloc(sizeof(int)* x);

	for (int i = 0; i < x; i++) {
		arr[i] = i;
	}
	permuteUtil(arr, x, n, 0);
}

int main() {
	int x, n;
	scanf("%d%d", &x, &n);

	if (x < 0 || x > 10) {
		printf("The value for first input should be between 0 to 10.");
	}
	else {
		xpermute(x, n);
		if (outputCount == 0) {
			printf("There is no permutation satisfying the input parameters.");
		}
	}
	return 0;
}