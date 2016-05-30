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

// https://www.hackerearth.com/problem/algorithm/circ-bear-and-vectors/

class Point{
public:
	long long int x;
	long long int y;
	Point(long long int a, long long int b){
		x = a;
		y = b;
	};
	Point operator+(const Point &point) const
	{
		return Point(x + point.x, y + point.y);
	}

	double GetAngle(){
		return atan2(y, x) * 180 / M_PI;
	}
};

void vectors(){
	int n;
	cin >> n;
	Point * arr = (Point *)malloc(sizeof(Point) * n);
	double ** sum = (double **)malloc(sizeof(Point*) * n);
	for (int i = 0; i < n; i++){
		sum[i] = (double *)malloc(sizeof(double) * n);
	}

	for (int i = 0; i < n; i++){
		long long int x, y;
		cin >> x >> y;
		Point p = Point(x, y);
		arr[i] = p;
	}

	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			if (i == j){
				sum[i][j] = INT_MAX;
			}
			else{
				Point sumPoint = arr[i] + arr[j];
				if (sumPoint.x == 0 && sumPoint.y == 0){
					sum[i][j] = INT_MAX;
				}
				else{
					sum[i][j] = sumPoint.GetAngle();
				}
			}
		}
	}

	long long int ans = 0;
	for (int i = 0; i < n; i++){
		double angle = arr[i].GetAngle();
		for (int j = 0; j < n; j++){
			if (i == j) continue;
			for (int k = j + 1; k < n; k++){
				bool diff1 = abs(abs(angle - sum[j][k]) - 90) < 0.001;
				bool diff2 = abs(abs(angle - sum[j][k]) - 270) < 0.001;
				if (diff1 || diff2){
					ans = ans + 2;
				}
			}
		}
	}

	cout << ans << endl;
}

// https://www.hackerearth.com/code-monk-number-theory-i/algorithm/the-confused-monk/
void fxPowergx(){
	long long mod = 1000000007;
	int n;
	cin >> n;
	int * arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int gcd = GetgcdOfN(arr, n);
	long long int  ans = 1;
	for (int i = 0; i < n; i++){
		int tempgcd = gcd;
		long long a = arr[i];
		while (tempgcd > 0){
			if (tempgcd & 1){
				ans = (ans * a) % mod;
			}

			a = (a * a) % mod;
			tempgcd /= 2;
		}
	}

	cout << ans;
}