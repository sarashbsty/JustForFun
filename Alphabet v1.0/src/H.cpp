#include<iostream>
#include "alphafunc.h"
using namespace std;

string H(int size,int row,char style){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size + 2*n;
	string str(max,' ');
	if(row == 0) return str;
	
	int x = row - (size/2+1);
	if(x < 0) x = -x - (n%2);
	x = x + (n-1)/2; // adjustment
	
    if(row >= (size-size/2)-(n/2) && row <= (size/2+1)+(n/2)) 
		for(int i = 1+(n-x); i <= max-(n-x); i++) str[i-1] = style;
	else{
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max-n; i <= max; i++)	str[i-1] = style;
	}
	return str;
}