#include<iostream>
#include "alphafunc.h"
using namespace std;

string K(int size,int row,char style){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = (size+bool(n))+(n*2)-(n%2);    // (n*2) adjust max according to increasing 'n'. (n%2) adjust max according to odd or even 'n'
	string str(max,' ');
	if(row == 0) return str;
	
	int x = (row <= size-size/2) ? (row-1)*2 - 1 : (size-row)*2 - 1;  // produces -1 1 3...
	if(row == 1 || row == size) x++;    // make it 0 1 3 5 ...
		
	for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	for(int i = max-x-n; i <= max-x; i++) str[i-1] = style;
		
	return str;
}