#include<iostream>
#include "alphafunc.h"
using namespace std;

string N(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = ((size/2+1)*2 + 3) + (n*3);
	string str(max,' ');
	if(row == 0) return str;
	
	int x = (size-1)/2;    //(size-1)/2 gives like 2 2 3 3 4 4
	
	for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	for(int i = max-n; i <= max; i++) str[i-1] = style;
	
	if(row < (size-size/2)-(n/2)) 
		for(int i = 1+row+n; i <= 1+row+(2*n); i++) str[i-1] = style;
	else if(row <= (size/2+1)+(n/2))  
		for(int i = (1+row*2)-x+n; i <= (1+row*2)-x+(2*n); i++) str[i-1] = style;   
	else 
		for(int i = max-1-(size-row)- (2*n); i <= max-1-(size-row)-n; i++) str[i-1] = style;
	return str;
}