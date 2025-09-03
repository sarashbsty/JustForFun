#include<iostream>
#include "alphafunc.h"
using namespace std;

string E(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size-1;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1; i <= max-(row-1); i++) str[i-1] = style;
	else if(row >= (size-size/2)-(n/2) && row <= (size/2+1)+(n/2))
		for(int i = 1; i <= max-1-n; i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 1; i <= max-(size-row); i++) str[i-1] = style;
	else
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	return str;
}