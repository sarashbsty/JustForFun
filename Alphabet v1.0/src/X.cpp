#include<iostream>
#include "alphafunc.h"
using namespace std;

string X(int size,int row,char style){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - 3 + n - 2*(n%2);   // n : adjust max according increasing n and 2*(n%2) : adjust max according to odd or even n
	string str(max,' ');
	if(row == 0) return str;
	
	bool m = size%2;
	int x = row - (size/2 + 1);
	if(x < 0) x = -x - (n%2);	
	x = x*2 + max/2 + (n/2);
	if(row%(size-1)==1) x--;
	
	for(int i = max-x; i <= max-x+n; i++) str[i-1] = style;
	for(int i = x+1-n; i <= x+1; i++) str[i-1] = style;
	return str;
}