#include<iostream>
#include "alphafunc.h"
using namespace std;

string I(int size,int row,char style){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - (5-n);
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1+(row-1); i <= max-(row-1); i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 1+(size-row); i <= max-(size-row); i++) str[i-1] = style;
	else
		for(int i = (max-max/2)-(n/2); i <= (max/2+1)+(n/2); i++) str[i-1] = style;
	return str;
}