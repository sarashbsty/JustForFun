#include<iostream>
#include "alphafunc.h"
using namespace std;

string O(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = (size*2)-1;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n)
		for(int i = 2+n-(row-1); i <= (max-1)-(n-(row-1)); i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 2+n+(row-size); i <= (max-1)-n+(size-row); i++) str[i-1] = style;
	else{ 
		for(int i = 1; i <= 2+n; i++) str[i-1] = style;
		for(int i = max-n-1; i <= max; i++) str[i-1] = style;
	}
	return str;
}