#include<iostream>
#include "alphafunc.h"
using namespace std;

string T(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = ((size-1)/2)*4 - 1 + (n%2);
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1; i <= max; i++) str[i-1] = style;
	else
		for(int i = max-(max/2); i <= max/2+1; i++) str[i-1] = style;
	return str;
}