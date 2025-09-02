#include<iostream>
#include "alphafunc.h"
using namespace std;

string V(int size,int row,char style){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - 1;
	string str(max,' ');
	if(row == 0) return str;
	
	if (row >= size-n) n = size-row;
	for(int i = row; i <= row+n; i++) str[i-1] = style;
	for(int i = max-(row-1)-n; i <= max-(row-1); i++) str[i-1] = style;
	return str;
}