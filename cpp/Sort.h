#define _USE_MATH_DEFINES
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>

using namespace std;

// https://www.hackerearth.com/problem/algorithm/puchi-and-luggage/description/
void merge(int start, int mid, int end, int* arr, int* pos, int* loc){
	int *tmp = (int*)malloc(sizeof(int) * (end - start + 1));
	int *tmpLoc = (int*)malloc(sizeof(int) * (end - start + 1));
	int j = mid + 1, i = start, k = 0;
	for (i; i <= mid && j <= end;){
		if (arr[i] <= arr[j]){
			tmp[k] = arr[i];
			tmpLoc[k] = loc[i];
			pos[loc[i]] += j - (mid + 1);
			k++; i++;
		}
		else{
			int count = 0;
			while (arr[j] < arr[i] && j <= end){
				tmp[k] = arr[j];
				tmpLoc[k] = loc[j];
				j++; k++;
			}

		}
	}

	if (i <= mid){
		while (i <= mid){
			pos[loc[i]] += end - mid;
			tmp[k] = arr[i];
			tmpLoc[k] = loc[i];
			k++;
			i++;
		}
	}
	else{
		while (j <= end){
			tmp[k] = arr[j];
			tmpLoc[k] = loc[j];
			k++;
			j++;
		}
	}

	for (int i = start; i <= end; i++){
		arr[i] = tmp[i - start];
		loc[i] = tmpLoc[i - start];
	}
}

void mergeSortVariation(int start, int end, int* arr, int* pos, int* loc){
	if (end < start){
		throw "InvalidInput";
	}
	if (end == start){
		pos[start] = 0;
		return;
	}
	if (end - start < 2){
		pos[end] = 0;
		pos[start] = 0;
		if (arr[start] > arr[end]){
			int tmp = arr[end];
			arr[end] = arr[start];
			arr[start] = tmp;
			pos[start] = 1;
			loc[end] = start;
			loc[start] = end;
		}

		return;
	}

	int size = end - start + 1;
	int mid = start + (end - start) / 2;

	mergeSortVariation(start, mid, arr, pos, loc);
	mergeSortVariation(mid + 1, end, arr, pos, loc);
	merge(start, mid, end, arr, pos, loc);
}

void luggage(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int* arr = (int *)malloc(sizeof(int) * n);
		int* pos = (int *)malloc(sizeof(int) * n);
		int* loc = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++){
			cin >> arr[i];
			loc[i] = i;
		}

		mergeSortVariation(0, n - 1, arr, pos, loc);
		for (int i = 0; i < n; i++){
			cout << pos[i] << " ";
		}
		cout << endl;
	}
}
