/*
	Copyright (c) 2025 Sarash Basumatary 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include<iostream>
#include<fstream>
#include "alphafunc.h"
using namespace std;

int main(){
	void homescreen();													    // Declarations
	void user_input(string &str,int &size,char &style, char &choice);		// Declarations
	void display(string str,int size,char style,char choice);			    // Declarations
	void print(string str,int size,char style,char choice);                 // Declarations
	
    string word = "";
	int size;
	char style,choice,choice2;
	
	system("cls");
	homescreen();
	user_input(word,size,style,choice);
	  
	system("cls");
	display(word,size,style,choice);
 		  
	cout<<"\nSize : "<<size<<endl;
	cout<<"Choice : "<<choice<<endl;
	if(choice == '2') cout<<"Style : "<<style<<endl<<endl;
	
	cout<<"\n\nEnter y to print, or anything to exit : ";
	cin>>choice2;
	if(choice2 == 'y' || choice2 == 'Y'){
		print(word,size,style,choice);
		cout<<"Done";
	}
	
    return 0;
}

void homescreen(){
	
	string alphabet(char ch,int size,int row,char style = '~');
	cout<<endl;
	string str = "ALPHABET";
	for(int row = 1; row <= 7; row++){
		cout<<"\t\t";
		for(int n = 0; str[n] != '\0'; n++) cout<<alphabet(str[n],7,row)<<"  ";
		cout<<endl;
	}
	cout<<"\n\n\n\n";
	
	str = "ABC";
	for(int row = 1; row <= 5; row++){
		cout<<"\t";
		for(int n = 0; str[n] != '\0'; n++) cout<< alphabet(str[n],5,row) <<"  ";
		cout<<"\t\t";
		for(int n = 0; str[n] != '\0'; n++) cout<< alphabet(str[n],5,row,'*') << "  ";
		cout<<"\t\t";
		for(int n = 0; str[n] != '\0'; n++) cout<< alphabet(str[n],5,row,60+n) << "  ";
		cout<<endl;
	}
	cout<<"\n\t     \e[7m(1)\e[0m Linear\t\t\t    \e[7m(2)\e[0m Custom \t\t\t      \e[7m(3)\e[0m Mixed \n\n";
}
	
void user_input(string &str,int &size,char &style, char &choice){
	
	cout<<"Choose a style (eg. 1,2,3) : "; cin>>choice;
	while(choice < '1' || choice > '3'){
		cout<<"INVALID. Choose correct option(1 - 3): "; 
		cin>>choice;
	}
	
	if(choice == '2'){ 
		cout<<"'--- Enter the custom character : "; cin.sync(); cin>>style; 
		while(style == '~'){ 
		cout<<"(~)Not available. Enter another : ";
		cin>>style;
		}
	}
	
	char choice2;
	cout<<"Input from (1) keyboard or (2) file : "; cin.sync(); cin>>choice2; 
	while(choice2 < '1' || choice2 > '2'){
		cout<<"INVALID. Choose correct option(1 or 2): "; 
		cin>>choice2;
	}
	switch(choice2){
		case '1' : cout<<"'--- Enter your Sentence : "; 
				   cin.sync(); getline(cin,str); 
				   str.push_back('\n');
				   break;
				   
		case '2' : cout<<"'--- Enter Name or directory of the file : "; cin.sync(); getline(cin,str); 
				   ifstream file(str);
				   if(file.is_open()){
					    string line; str = "";
						cout<<"File : ";
						while(getline(file,line)){
							cout<<"\t"<<line<<endl;
							str.append(line).append("\n");
						}
				    }
				   else{ cout<<str<<" not found. exiting...."; exit(1); }	
	}
	
	cout<<"Size (eg. 5,6,7...) : "; cin >> size;
	while(size < 5){
		if(cin.fail()) cin.clear();
		cin.sync();
		cout<<size<<" way too small. Enter higher : ";
		cin>>size;
	}
	
}  

void display(string str,int size,char style,char choice){
	
	string alphabet(char ch,int size,int row,char style);      // Declaration
    cout<<endl;
	int n,m = 0;
	switch(choice){
		case '1':	while(m < str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								cout<<alphabet(str[n],size,row,'~')<<"  ";
							cout<<endl;
						}
						cout<<endl;
						m = n+1;
					}
					break;
					
		case '2':	while(m < str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								cout<<alphabet(str[n],size,row,style)<<"  ";
							cout<<endl;
						}
						cout<<endl;
						m = n+1;
					}
					break;
					
		case '3':	while(m != str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								cout<<alphabet(str[n],size,row,35+n)<<"  ";
							cout<<endl;
						}
						cout<<endl;
						m = n+1;
					}
					break;
	} 
}

void print(string str,int size,char style,char choice){
	
	string alphabet(char ch,int size,int row,char style = '~');
	ofstream file("alphabet.txt");
	int n,m = 0;
	switch(choice){
		case '1':	while(m < str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								file<<alphabet(str[n],size,row,'~')<<"  ";
							file<<endl;
						}
						file<<endl;
						m = n+1;
					}
					break;
					
		case '2':	while(m < str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								file<<alphabet(str[n],size,row,style)<<"  ";
							file<<endl;
						}
						file<<endl;
						m = n+1;
					}
					break;
					
		case '3':	while(m != str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								file<<alphabet(str[n],size,row,35+n)<<"  ";
							file<<endl;
						}
						file<<endl;
						m = n+1;
					}
					break;
	} 
	file.close();
}

string alphabet(char ch, int size, int row, char style){
	string (*letter[26])(int, int, char) = { A, B, C, D, E, F, G, H,I,  // Function selector
											 J, K, L, M, N, O, P, Q, R, 
											 S, T, U, V, W, X, Y, Z };
											 
	ch = toupper(ch);
	if(style == '~') style = ch;
	
	int index = ch - 'A';
	if(ch >= 'A' && ch <= 'Z') return letter[index](size,row,style);
	else if(ch == ' ') return "   ";
	else return "ERROR";
} 












