#include<iostream>
#include<fstream>
#include <limits>
#include "iofunc.h"
#define clear_buffer std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
using namespace std;

void user_input(string &str,int &size,char &style, char &choice){
	
	cout<<"Choose a style (0 to exit) : "; cin>>choice; clear_buffer;
	while(choice < '0' || choice > '3'){
		cout<<"INVALID. Choose correct option(1 - 3): "; 
		cin>>choice;
		clear_buffer;
	}
	
	if(choice == '0') exit(0);
	
	if(choice == '2'){ 
		cout<<"'--- Enter the custom character : "; cin>>style; clear_buffer;
		while(style == '~'){ 
		cout<<"(~)Not available. Enter another : ";
		cin>>style;
		clear_buffer;
		}
	}
	
	char choice2;
	cout<<"Input from (1) file or (2) keyboard : "; cin>>choice2; clear_buffer;
	while(choice2 < '1' || choice2 > '2'){
		cout<<"INVALID. Choose correct option(1 or 2): "; 
		cin>>choice2;
		clear_buffer;
	}
	switch(choice2){		   
		case '1' :{  // need to create block. remove and see the error. compiler dependent
					cout<<"'--- Enter Name or directory of the file : "; getline(cin,str); 
				    ifstream file(str);
				    if(file.is_open()){
					    string line; str = "";
						cout<<"File : ";
						while(getline(file,line)){
							cout<<"\t"<<line<<endl;
							str.append(line).append("\n");
						}
						break;
				    }
				    else cout<<str<<" not found. Instead....\n"; 
				}
				
		case '2' : cout<<"'--- Enter your Sentence : "; 
				   getline(cin,str); 
				   str.push_back('\n');
	}
	
	cout<<"Size (eg. 5,6,7...) : "; cin >> size;
	while(size < 5){
		if(cin.fail()){
			cin.clear();
			clear_buffer;
		}
		cout<<size<<" way too small. Enter higher : ";
		cin>>size;
	}	
}  