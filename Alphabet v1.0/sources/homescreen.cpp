#include<iostream>
#include "iofunc.h"
#include "alphabet.h" //For generate Function
using namespace std;

void homescreen(){
	
	cout<<endl;
	string str = "ALPHABET";
	for(int row = 1; row <= 7; row++){
		cout<<"\t\t";
		for(int n = 0; str[n] != '\0'; n++) cout<< generate(str[n],7,row)<<"  ";
		cout<<endl;
	}
	cout<<"\n\n\n\n";
	
	str = "ABC";
	for(int row = 1; row <= 5; row++){
		cout<<"\t";
		for(int n = 0; str[n] != '\0'; n++) cout<< generate(str[n],5,row) <<"  ";
		cout<<"\t\t";
		for(int n = 0; str[n] != '\0'; n++) cout<< generate(str[n],5,row,'*') << "  ";
		cout<<"\t\t";
		for(int n = 0; str[n] != '\0'; n++) cout<< generate(str[n],5,row,60+n) << "  ";
		cout<<endl;
	}
	cout<<"\n\t     \e[7m(1)\e[0m Linear\t\t\t\t    \e[7m(2)\e[0m Custom \t\t\t\t      \e[7m(3)\e[0m Mixed \n\n";
}