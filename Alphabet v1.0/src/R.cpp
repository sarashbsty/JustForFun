#include<iostream>
#include "alphafunc.h"
using namespace std;

string R(int size,int row,char style){
	if(size == 11) size--;
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int x = size-(size/2);
	int max = x*2 - 1;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n)  
		for(int i = 2+n-row; i <= max-2-n+row; i++) str[i-1] = style;
	else if(row < x-n){
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max-n; i <= max; i++) str[i-1] = style;
	}
	else if(row <= x)
		for(int i = 1; i <= max-1-n+(x-row); i++) str[i-1] = style;
	else{
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max-(size-row)-n; i <= max-(size-row); i++) str[i-1] = style;
	}
	return str;
}