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

void smack1(){
	// http://www.codechef.com/SNCK151C/problems/DEVJERRY
	int t;
	cin >> t;
	while (t--){
		int n, sa, sb, ea, eb, ba, bb;
		cin >> n >> sa >> sb >> ea >> eb >> ba >> bb;
		if (sa == ea){
			if (ba == sa && ((bb < sb && bb > eb) || (bb > sb && bb < eb))){
				cout << abs(sb - eb) + 2 << endl;
			}
			else{
				cout << abs(sb - eb) << endl;
			}
		}
		else if (sb == eb){
			if (bb == sb && ((ba < sa && ba > ea) || (ba > sa && ba < ea))){
				cout << abs(sa - ea) + 2 << endl;
			}
			else{
				cout << abs(sa - ea) << endl;
			}
		}
		else{
			cout << abs(sa - ea) + abs(sb - eb) << endl;
		}
	}
}

void smack2(){
	// http://www.codechef.com/SNCK151C/problems/ANKINTER

	int t;
	cin >> t;
	while (t--){
		int n, w;
		cin >> n >> w;
		int* a = (int *)malloc(sizeof(int) * n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		long long int ans = 0;
		for (size_t i = 0; i + w <= n; i++)
		{
			int Visited[100000] = { 0 };
			int min = 100000;
			int max = 0;
			long long int sum = 0;
			bool brk = false;
			for (size_t j = i; j < i + w; j++)
			{
				if (Visited[a[j]] != 0){
					brk = true;
					i = j;
					break;
				}

				sum += a[j];
				Visited[a[j]] = 1;
				if (a[j] < min) min = a[j];
				if (a[j] > max) max = a[j];
			}

			if (brk) continue;

			if (max - min == w - 1){
				long long int expSum = (max * (max + 1)) / 2 - (min * (min - 1)) / 2;
				if (sum == expSum){
					ans++;
				}
			}

			for (size_t j = i + w; j < n; j++)
			{
				if (Visited[a[j]] != 0){
					brk = true;
					break;
				}

				sum += a[j];
				Visited[a[j]] = 1;
				if (a[j] < min) min = a[j];
				if (a[j] > max) max = a[j];
				if (max - min == (j - i)){
					long long int expSum = (max * (max + 1)) / 2 - (min * (min - 1)) / 2;
					if (sum == expSum){
						ans++;
					}
				}
			}

			if (brk) continue;
		}

		cout << ans << endl;
	}
}

void smack3(){
	// http://www.codechef.com/SNCK15EL/problems/TTENIS
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int won = 0, lose = 0;
		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '0'){
				lose++;
			}
			else{
				won++;
			}
		}

		if (won > lose) cout << "WIN" << endl;
		else cout << "LOSE" << endl;
	}
}

void smack4(){
	// http://www.codechef.com/SNCK15EL/problems/DIVNINE
	int t;
	cin >> t;
	while (t--){
		string n;
		cin >> n;
		int length = n.size();
		int sum = 0;
		int incrementable = 0;
		for (size_t i = 0; i < length; i++)
		{
			int num = n[i] - '0';
			sum += num;
			incrementable += 9 - num;
		}
		int k = n[0] - '0';
		int removable = sum - (k == 1 ? 1 : k - 1);
		if (length == 1) removable = k;
		int rem = sum % 9;
		if (rem <= 4){
			if (removable >= rem){
				cout << rem << endl;
				continue;
			}
			else{
				cout << 9 - rem << endl;
			}
		}
		else if (incrementable >= 9 - rem) cout << 9 - rem << endl;
		else cout << rem << endl;

	}
}

void smack5(){
	// http://www.codechef.com/SNCK15EL/problems/ANKLEX
	string s;
	cin >> s;
	int count[26] = { 0 };
	int length = s.size();
	for (size_t i = 0; i < length; i++)
	{
		int index = s[i] - 'a';
		count[index]++;
	}

	int q;
	cin >> q;
	while (q--)
	{
		int tempCount[26] = { 0 };
		for (size_t i = 0; i < 26; i++)
		{
			tempCount[i] = count[i];
		}

		int start, len;
		cin >> start >> len;
		string substring = s.substr(start - 1, len);
		int l = substring.size();
		for (size_t i = 0; i < l; i++)
		{
			int index = substring[i] - 'a';;
			tempCount[index]--;
		}
		bool brk = false;
		int lookup = -1;
		for (size_t i = l - 1; i >= 0; i--)
		{
			int index = substring[i] - 'a';
			for (size_t j = index + 1; j < 26; j++)
			{
				if (tempCount[j] > 0){
					if (i == 0){
						lookup = j;
					}
					brk = true;
					break;
				}
			}
			if (brk) break;
		}
		if (brk){
			if (lookup == -1){
				cout << start << endl;
			}
			else{
				char lk = 'a' + lookup;
				for (size_t i = 0; i < length; i++)
				{
					if (s[i] == lk){
						cout << i + 1 << endl;
						break;
					}
				}
			}
		}
		else{
			cout << -1 << endl;
		}
	}
}