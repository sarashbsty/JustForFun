#include<iostream>
#include "alphafunc.h"
using namespace std;

string A(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = size*2 - 1;
	string str(max,' ');
	
	int mid = max/2 + 1;
	if(row <= n) n = row-1;
	for(int i = mid-(row-1); i <= mid-(row-1)+n; i++) str[i-1] = style;
	for(int i = mid+(row-1)-n; i <= mid+(row-1); i++) str[i-1] = style;
	if(row >= size*21/25 - n && row <= size*21/25)
		for(int i = mid-row+2; i < mid+row-1; i++) str[i-1] = style;

	return str;
}