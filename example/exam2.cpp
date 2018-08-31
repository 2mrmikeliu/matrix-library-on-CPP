#include<iostream>
#include<stdio.h>
using namespace std;
#include "Matrix.h"
matrix<int> m1(2,2),m2(2,2);
int main()
{
	int arr[2][2]={{1,2},{1,3}};
	m1.PutArray((int**)arr,2,2);
	m2.PutArray((int**)arr,2,2);
	(m1*m2).PrintFormat();
	return 0;
}

