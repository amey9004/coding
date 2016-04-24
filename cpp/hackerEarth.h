#define _USE_MATH_DEFINES
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <ctype.h>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

void chipmonk1(){
	int t;
	cin >> t;
	while (t--){
		long long n, k;
		cin >> n >> k;

		long long sum = n % 2 == 0 ? (n / 2) * (n + 1) : ((n + 1) / 2) * n;
		if (k <= sum){
			cout << sum - k << endl;
		}
		else{
			if (k % sum == 0){
				cout << 0 << endl;
			}
			else{
				cout << (sum - (k % sum)) << endl;
			}
		}
	}
}

void chipmonk2(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int *a = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0;
		int length = 0;
		for (int i = 1; i < (1 << n); i++){
			int localXor = 0;
			int localAnd = std::numeric_limits<int>::max();
			int localLenght = 0;
			for (int j = 0; j < n; j++){
				if (i & (1 << j)){
					localAnd = localAnd & a[j];
					localXor = localXor ^ a[j];
					localLenght++;
				}
			}
			int local = localXor | localAnd;
			if (local > ans){
				ans = local;
				length = localLenght;
			}
			else if (local == ans && localLenght > length){
				length = localLenght;
			}
		}
		cout << ans << " " << length << endl;
	}
}