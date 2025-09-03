#include<iostream>
#include "alphafunc.h"
using namespace std;

string B(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = size;
	string str(max,' ');
	if(row == 0) return str;
	
	int x = row - (size/2+1);      // for middle row design
	if(x < 0) x = -x - (n%2);
	
	if(row >= 1 && row <= 1+n) 
		for(int i = 1+n-(row-1); i <= max-1-n+(row-1)-((n+1)/2); i++) str[i-1] = style;
	else if(row >= (size-size/2) - (n/2) && row <= (size/2+1) + (n/2))
		for(int i = 1; i <= max-1-n+x; i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 1+n-(size-row); i <= max-1-n+(size-row)-((n+1)/2); i++) str[i-1] = style;
	else{
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max-((n+1)/2); i <= max; i++) str[i-1] = style;
	}
	
	return str;
}