#include<iostream>
#include<fstream>
#include "iofunc.h"
using namespace std;

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