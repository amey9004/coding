#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

#define mod 1000000007

using namespace std;

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
	if (i < ss || i > se){
		return;
	}

	st[si] = ((long long)st[si] + (long long)diff) % mod;
	if (se != ss)
	{
		int mid = ss + (se - ss) / 2;
		updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
		updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
	}
}

void updateValue(int arr[], int *st, int n, int i, int new_val)
{
	if (i < 0 || i > n - 1)
	{
		printf("Invalid Input");
		return;
	}

	int diff = new_val - arr[i];
	arr[i] = new_val;
	updateValueUtil(st, 0, n - 1, i, diff, 0);
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
	if (qs <= ss && qe >= se){
		return st[si];
	}

	if (se < qs || ss > qe){
		return 0;
	}

	int mid = ss + (se - ss) / 2;
	return ((long long)getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
		(long long)getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2)) % mod;
}

int getSum(int *st, int n, int qs, int qe)
{
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		printf("Invalid Input");
		return -1;
	}

	return getSumUtil(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = ss + (se - ss) / 2;
	st[si] = ((long long)constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
		(long long)constructSTUtil(arr, mid + 1, se, st, si * 2 + 2)) % mod;
	return st[si];
}

int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));
	int max_size = 2 * (int)pow(2, x) - 1;
	int *st = new int[max_size];
	constructSTUtil(arr, 0, n - 1, st, 0);
	return st;
}

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

int getGcd(int n){
	int ret = 0;
	for (int i = n; i > 0; i--){
		ret += gcd(n, i);
	}
	return ret;
}

void amazonGcd(){
	int n, q;
	cin >> n;
	int * arr = (int *)malloc(sizeof(int) * n);
	int * gcdArr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		gcdArr[i] = getGcd(arr[i]);
	}
	int* segTree = constructST(gcdArr, n);
	cin >> q;
	while (q--){
		getchar();
		char op = getchar();
		getchar();
		int a, b;
		cin >> a >> b;
		if (op == 'C'){
			cout << getSum(segTree, n, a - 1, b - 1) << endl;
		}
		else{
			arr[a-1] = b;
			int newVal = getGcd(b);
			updateValue(gcdArr, segTree, n, a - 1, newVal);
		}
	}
}