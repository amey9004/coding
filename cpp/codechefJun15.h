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

void problem1(){
	// http://www.codechef.com/JUNE15/problems/CBARG

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int* A = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}

		long long int answer = A[0];
		for (int i = 1; i < n; i++)
		{
			if (A[i] > A[i - 1])
			{
				answer += (A[i] - A[i - 1]);
			}
		}

		cout << answer << endl;
	}
}

void problem2()
{
	// http://www.codechef.com/JUNE15/problems/FRNDMTNG

	int t;
	double T1, T2, t1, t2;
	cin >> t;
	while (t--)
	{
		cin >> T1 >> T2 >> t1 >> t2;
		double l, u;
		if (t2 > T1){
			l = 0;
		}
		else if ((T2 + t2) < T1){
			l = (((T2 * T2) / 2) + (T2 * (T1 - (t2 + T2))));
		}
		else{
			l = ((T1 - t2) * (T1 - t2)) / 2;
		}

		if (t1 > T2){
			u = 0;
		}
		else if ((T1 + t1) < T2){
			u = (((T1 * T1) / 2) + (T1 * (T2 - (t1 + T1))));
		}
		else{
			u = ((T2 - t1) * (T2 - t1)) / 2;
		}

		cout << 1 - ((l + u) / (T1 * T2)) << endl;
	}
}

struct Point
{
	double x;
	double y;
};

double GetAreaOfPolygon(Point* p, size_t n){

	if (n == 2) return 0;
	double ans = 0;
	for (size_t i = 0; i < n; i++){
		size_t j = (i + 1) % n;
		ans = ans + (double)(p[i].x*p[j].y - p[i].y*p[j].x) / 2;
	}

	return abs(ans);
}

class Data{
public:
	double area;
	int num;
};

bool comparer(Data a, Data b) { return (a.area < b.area); }

void problem3(){
	// http://www.codechef.com/JUNE15/problems/CHPLGNS

	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		int * size = (int *)malloc(sizeof(int) * n);
		vector<Data> myvector;
		for (size_t i = 0; i < n; i++)
		{
			cin >> size[i];
			Point* cord = (Point *)malloc(sizeof(Point) * size[i]);
			for (size_t j = 0; j < size[i]; j++)
			{
				int x, y;
				cin >> x >> y;
				cord[j].x = x;
				cord[j].y = y;
			}

			Data entity;
			entity.area = GetAreaOfPolygon(cord, size[i]);
			entity.num = i;
			myvector.push_back(entity);
		}

		int* answers = (int *)malloc(sizeof(int) *n);
		sort(myvector.begin(), myvector.end(), comparer);

		for (size_t i = 0; i < n; i++)
		{
			answers[myvector[i].num] = i;
		}

		for (size_t i = 0; i < n; i++)
		{
			cout << answers[i] << " ";
		}

		cout << endl;
	}
}
