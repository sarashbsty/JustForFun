#include<iostream>
#include "alphafunc.h"
using namespace std;

string W(int size,int row,char style){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	size -= n; row -= n;
	int max = (size*2)-1 + n*2;
	string str(max,' ');
	if(row+n == 0) return str;
	
	int x = (row <= 1) ? (row+n-1) : n;            // row+n <= 1+n   --> row <= 1 . since we substracted n from row, we are adding it back to work like usual
	int y = (row >= size-n) ? n-(size-row)+1 : 0;
	for(int i = 1+y; i <= 1+x; i++) str[i-1] = style;
	for(int i = max-x; i <= max-y; i++) str[i-1] = style;
	
	if(row <= n+1) n = row-2;
	int mid = (max/2)+1;
	for(int i = (mid-row+2); i <= (mid-row+2)+n; i++) str[i-1] = style;
	for(int i = (mid+row-2)-n; i <= (mid+row-2); i++) str[i-1] = style;
	
	return str;
}