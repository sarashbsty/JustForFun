#include<iostream>
#include "alphafunc.h"
using namespace std;

string Y(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = (size-(size/2))*4 - 3 + n;
	string str(max,' '); 
	if(row == 0) return str;
	
	int x = row*2 - 2;
	if(row < size-(size/2)){ 
		for(int i = x; i <= x+n; i++) str[i] = style;		
		for(int i = (max-1)-x-n; i <= (max-1)-x; i++) str[i] = style;
	}
	else 
		for(int i = (max-max/2)-(n/2) ; i <= max/2+1+(n/2); i++) str[i-1] = style;
	return str;
}