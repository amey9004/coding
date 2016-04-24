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

using namespace std;

void walls(){
	// https://www.hackerearth.com/problem/algorithm/walls-of-the-north/description/
	// can be optimized
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int* a = (int*)malloc(sizeof(int)*n);
		int *inc = (int*)malloc(sizeof(int)*n);
		int *dec = (int*)malloc(sizeof(int)*n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		inc[0] = dec[0] = 1;
		for (int i = 1; i < n; i++){
			int maxInc = 0, maxDec = 0;
			for (int j = i - 1; j >= 0; j--){
				if (inc[j] > maxInc && a[i] <= a[j]){
					maxInc = inc[j];
				}
				if (dec[j] > maxDec && a[i] >= a[j]){
					maxDec = dec[j];
				}
			}
			inc[i] = maxDec + 1;
			dec[i] = maxInc + 1;
		}
		int ans = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (ans < inc[i]){
				ans = inc[i];
			}
			if (ans < dec[i]){
				ans = dec[i];
			}
		}
		cout << ans << endl;
	}
}