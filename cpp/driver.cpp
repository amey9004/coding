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

#include "linkedList.h"

using namespace std;


int main() {
	int arr[] = { 9 };
	int arr2[] = { 1, 9 };
	Node* num1 = GetLinkedList(arr, 1);
	Node* num2 = GetLinkedList(arr2, 2);
	Node* sum = SumLinkedList(num1, num2);
	printList(sum);
}
