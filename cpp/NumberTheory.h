#define _USE_MATH_DEFINES
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <ctype.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

/*
https://www.hackerearth.com/problem/algorithm/a-simple-task/?utm_campaign=user-activity-email&amp;utm_medium=email&amp;utm_source=user-recommend-problemdescription/
*/
int gcd(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int GetgcdOfN(int * arr, int size){
	if (size < 1) return -1;
	int result = arr[0];
	if (size == 1) return result;
	for (int i = 1; i < size; i++){
		result = gcd(result, arr[i]);
	}
	return result;
}

void PrintAllDivisors(int n){
	if (n <= 1) return;
	if (n == 2 || n == 3) {
		cout << n << endl;
		return;
	}
	int root = ceil(sqrt(n));
	for (int i = 2; i <= root; i++){
		if (n % i == 0) cout << i << " ";
	}
	for (int i = root; i >= 2; i--){
		if (n % i == 0 && i * i != n) cout << n / i << " ";
	}
	cout << n << endl;
}

void HelpOz(){
	int n;
	cin >> n;
	int * arr = (int *)malloc(n * sizeof(int));
	int * diff = (int *)malloc((n - 1) * sizeof(int));
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++){
		diff[i] = arr[i + 1] - arr[i];
	}

	int gcd = GetgcdOfN(diff, n - 1);
	PrintAllDivisors(gcd);
}

void zeros(){
	// https://www.hackerearth.com/algorithms-qualifiers-round-3/algorithm/zeroes/
	// NOT ALL CASES COVERED
	int n;
	cin >> n;
	int* a = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int q;
	cin >> q;
	while (q--){
		int ans = 0;
		int t;
		cin >> t;
		for (int i = 0; i < n; i++){
			while (a[i] % t == 0){
				ans++;
				a[i] = a[i] / t;
			}
		}
		cout << ans << endl;
	}
	return;
}