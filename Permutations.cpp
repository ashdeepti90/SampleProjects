// C program to print all permutations statisfying condition sum(arr[i]*i)<=n

#include <stdio.h>
#include <stdlib.h>

int outputCount; //variable to check the number of valid permutations

// <summary>
// Print permuted array satisfying condition sum(arr[i]*i)<=n
// </summary>
// <param name="arr">Permuted Array</param>
// <param name="x">Array Size</param>
// <param name="n">Sum for valid permutation</param>
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

// <summary>
// Generate all Permutations
// </summary>
// <param name="arr">Permuted Array</param>
// <param name="x">Array Size</param>
// <param name="n">Sum for valid permutation</param>
// <param name="st">Start index for permutations</param>
void permuteUtil(int arr[], int x, int n, int st) {
	if (st == x - 1) {
		print(arr, x, n); //Print all the leaf nodes of the recursion tree
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

// <summary>
// Generate all Permutations satisfying condition sum(arr[i]*i)<=n
// </summary>
// <param name="x">Array Size</param>
// <param name="n">Sum for valid permutation</param>
void xpermute(int x, int n) {
	int * arr = (int *)malloc(sizeof(int)* x);

	for (int i = 0; i < x; i++) {
		arr[i] = i;
	}
	permuteUtil(arr, x, n, 0);
}

// <summary>
// Driver Program
// </summary>
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
