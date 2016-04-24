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
 * https://www.hackerearth.com/nutanix-backend-hiring-challenge/problems/2966b72f6e6b46ae9cbe84a3d6a8d34a/
 */
void Execute(){
	string s;
	cin >> s;
	int q;
	cin >> q;
	long long int a[26] = { 0 };
	for (int i = 0; i < s.length(); i++){
		char ch = s[i];
		i++;
		int j = i;
		while (isdigit(s[i]) && i < s.length()){
			i++;
		}
		string number = s.substr(j, i - j);
		long long num = stoll(number);
		a[ch - 'a'] += num;
		i--;
	}
	while (q--){
		long long int k;
		cin >> k;
		long long int sum = 0;
		bool found = false;
		for (int i = 0; i < 26; i++){
			sum += a[i];
			if (sum >= k){
				printf("%c\n", 'a' + i);
				found = true;
				break;
			}
		}
		if (!found){
			cout << "-1\n";
		}
	}
}

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