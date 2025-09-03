#include<iostream>
#include "alphafunc.h"  // for functions A,B,C,....
#include "alphabet.h"
using namespace std;

string generate(char ch, int size, int row, char style){
	
	// Function selector
	string (*letter[26])(int, int, char) = { A, B, C, D, E, F, G, H,I,  
											 J, K, L, M, N, O, P, Q, R, 
											 S, T, U, V, W, X, Y, Z };
											 
	ch = toupper(ch);
	if(style == '~') style = ch;
	
	int index = ch - 'A';
	if(ch >= 'A' && ch <= 'Z') return letter[index](size,row,style);
	else if(ch == ' ') return "   ";
	else return "ERROR";
} 