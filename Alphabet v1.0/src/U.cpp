#include<iostream>
#include "alphafunc.h"
using namespace std;

string U(int size,int row,char style){
	int n = 1+(size/11);
	int k = size%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = (size*2)-1;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row >= size-n) 
		for(int i = 1+(row-size)+n; i <= max-n+(size-row); i++) str[i-1] = style;
	else{
		for(int i = 1; i <= max; i++) 
			if(i<=1+n || i>=max-n) str[i-1] = style;
	}
	return str;
}