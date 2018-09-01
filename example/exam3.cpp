#include<iostream>
#include<stdio.h>
using namespace std;
#include "Matrix.h"
matrix<int> m1(2,2);
int main()
{
	int arr[2][2]={{10,5},{1,3}};
	m1.PutArray((int**)arr,2,2);
	m1.ModValue=1e9+7;
	(m1^20).PrintFormat();
	return 0;
}

