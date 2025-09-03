#include<iostream>
#include "alphafunc.h"
using namespace std;

string Z(int size,int row,char style){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - 3 - (n*2);
	string str(max,' '); 
	if(row == 0) return str;
	
	int x = (max+1) - (row*2-2) + (n*2);
	if(row <= 1+n || row >= size-n) 
		for(int i = 1; i <= max; i += 2) str[i-1] = style;
	else 
		for(int i = x-(n*2); i <= x; i += 2) str[i-1] = style;
	
	return str;
}