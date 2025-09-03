#include<iostream>
#include "alphafunc.h"
using namespace std;

string L(int size,int row,char style){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size;
	string str(max,' ');
	if(row == 0) return str;

	if(row < size-n)
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	else 
		for(int i = 1+n-(size-row); i <= max; i++) str[i-1] = style;	
	return str;
}