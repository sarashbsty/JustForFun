#include<iostream>
#include "alphafunc.h"
using namespace std;

string M(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int MidRow = size-(size/2);
	int max = (MidRow*4 - 3) + (n*2);
	string str(max,' ');
	if(row == 0) return str;
	
	int x = (row == MidRow) ? row*2 - 2 + n : row*2 - 1 + n;
	int y = (row <= n) ? n-(row-1) : 0;
	int z = (row >= size-n) ? (size-row) : n;
	if(row >= MidRow-n) n = MidRow-row;
	
	if(row>1){
		for(int i = 1+y; i <= 1+z; i++) str[i-1] = style;
		for(int i = max-z; i <= max-y; i++) str[i-1] = style;
	}
	if(row <= MidRow){ 
		for(int i = 1+x; i <= 1+x+n; i++) str[i-1] = style;
		for(int i = max-x-n; i <= max-x; i++) str[i-1] = style;
	}
	return str;
}