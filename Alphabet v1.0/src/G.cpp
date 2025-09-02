#include<iostream>
#include "alphafunc.h"
using namespace std;

string G(int size,int row,char style){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = (size*2)-3;
	string str(max,' ');
	if(row == 0) return str;
	
	int x = ((size/2+1)+n)-row;  // middle row adjuster
	if(row <= 1+n)
		for(int i = 2+n-(row-1); i <= max-(size*3/10-row); i++) str[i-1] = style;
			
	else if(row <= size*3/10){		
		for(int i = 1; i <= 1+n; i++) str[i-1] = style; 
		for(int i = max-(size*3/10-row)-n; i <= max-(size*3/10-row); i++) str[i-1] = style; 
	}
	else if(row >= (size/2+1) && row <= (size/2+1)+n){
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = (max/2+1)+(size/8)-(n-x); i <= max-(size/8)+(n-x); i++) str[i-1] = style;
	}
	else if(row > (size/2)+1+n && row < size-n){ 
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max/2+1; i <= (max/2+1)+n; i++) str[i-1] = style;
		for(int i = max-n; i <= max; i++) str[i-1] = style;
	}
    else if(row >= size-n){ 
		for(int i = 2+n-(size-row); i <= (max/2+1)+(size-row); i++) str[i-1] = style;   // simplefied version of (max/2+1)-n+(size-row)+n        
		for(int i = max-n; i <= max; i++) str[i-1] = style;
	}
	else 
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	return str;
}