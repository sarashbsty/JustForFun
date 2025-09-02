#include<iostream>
#include "alphafunc.h"
using namespace std;

string Q(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int x = (size*21/25);
	int max = x*2 - 2;
	string str(max,' ');
	if(row == 0) return str;
		
	if(row <= 1+n)
		for(int i = 2+n-(row-1); i <= (max-1)-(n-(row-1)); i++) str[i-1] = style;
	else if(row < x-n){
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max-n; i <= max; i++) str[i-1] = style;
	}
	else if(row <= x)
		for(int i = 2+n-(x-row); i <= (max-1)-n+(x-row); i++) str[i-1] = style;
	if(row >= x-n-1) 
		for(int i = max-(size-row)-n; i <= max-(size-row); i++) str[i-1] = style;
	return str;
}