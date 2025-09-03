#include<fstream>
#include "alphabet.h" //For generate Function
#include "iofunc.h"
using namespace std;

void print(string str,int size,char style,char choice){
	
	ofstream file("alphabet.txt");
	int n,m = 0;
	switch(choice){
		case '1':	while(m < str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								file<<generate(str[n],size,row,'~')<<"  ";
							file<<endl;
						}
						file<<endl;
						m = n+1;
					}
					break;
					
		case '2':	while(m < str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								file<<generate(str[n],size,row,style)<<"  ";
							file<<endl;
						}
						file<<endl;
						m = n+1;
					}
					break;
					
		case '3':	while(m != str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								file<<generate(str[n],size,row,35+n)<<"  ";
							file<<endl;
						}
						file<<endl;
						m = n+1;
					}
					break;
	} 
	file.close();
}