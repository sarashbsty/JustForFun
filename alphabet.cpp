#include<iostream>
#include<fstream>
using namespace std;

int main(){
	void homescreen();
	void user_input(string &str,int &size,char &style, char &choice);
	void display(string str,int size,char style,char choice);
	void print(string str,int size,char style,char choice);
	
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
	
	string alphabet(char ch,int size,int row,char style);
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

string A(int size,int row,char style = 'A'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = size*2 - 1;
	string str(max,' ');
	
	int mid = max/2 + 1;
	if(row <= n) n = row-1;
	for(int i = mid-(row-1); i <= mid-(row-1)+n; i++) str[i-1] = style;
	for(int i = mid+(row-1)-n; i <= mid+(row-1); i++) str[i-1] = style;
	if(row >= size*21/25 - n && row <= size*21/25)
		for(int i = mid-row+2; i < mid+row-1; i++) str[i-1] = style;

	return str;
}

string B(int size,int row,char style = 'B'){
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

string C(int size,int row,char style = 'C'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = size;
	string str(max,' ');
	if(row  == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1+n-(row-1); i <= max-(row-1); i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 1+n-(size-row); i <= max-(size-row); i++) str[i-1] = style;
	else
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	
	return str;
}

string D(int size,int row,char style = 'D'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = size;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1; i <= (max-1)-n+(row-1); i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 1; i <= (max-1)-n+(size-row); i++) str[i-1] = style;
	else{
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max-n; i <= max; i++) str[i-1] = style;
	}
	
	return str;
}

string E(int size,int row,char style = 'E'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size-1;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1; i <= max-(row-1); i++) str[i-1] = style;
	else if(row >= (size-size/2)-(n/2) && row <= (size/2+1)+(n/2))
		for(int i = 1; i <= max-1-n; i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 1; i <= max-(size-row); i++) str[i-1] = style;
	else
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	return str;
}

string F(int size,int row,char style = 'F'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1; i <= max-(row-1); i++) str[i-1] = style;
	else if(row >= (size-size/2) - (n/2) && row <= (size/2+1) + (n/2))
		for(int i = 1; i <= max-1-n; i++) str[i-1] = style;
	else
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	return str;
}

string G(int size,int row,char style = 'G'){
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

string H(int size,int row,char style = 'H'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size + 2*n;
	string str(max,' ');
	if(row == 0) return str;
	
	int x = row - (size/2+1);
	if(x < 0) x = -x - (n%2);
	x = x + (n-1)/2; // adjustment
	
    if(row >= (size-size/2)-(n/2) && row <= (size/2+1)+(n/2)) 
		for(int i = 1+(n-x); i <= max-(n-x); i++) str[i-1] = style;
	else{
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max-n; i <= max; i++)	str[i-1] = style;
	}
	return str;
}

string I(int size,int row,char style = 'I'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - (5-n);
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1+(row-1); i <= max-(row-1); i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 1+(size-row); i <= max-(size-row); i++) str[i-1] = style;
	else
		for(int i = (max-max/2)-(n/2); i <= (max/2+1)+(n/2); i++) str[i-1] = style;
	return str;
}

string J(int size,int row,char style = 'J'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - 3 + n;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1+(row-1); i <= max-(row-1); i++) str[i-1] = style; 
	else if(row > size/2+1 && row < size-n){
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = (max-max/2)-(n/2); i <= (max/2+1)+(n/2); i++) str[i-1] = style;
	}
	else if(row >= size-n) 
		for(int i = 2+n-(size-row); i <= max/2+(n/2)-n+(size-row); i++) str[i-1] = style; 
	else 
		for(int i = (max-max/2)-(n/2); i <= (max/2+1)+(n/2); i++) str[i-1] = style;
	return str;
}

string K(int size,int row,char style = 'K'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = (size+bool(n))+(n*2)-(n%2);    // (n*2) adjust max according to increasing 'n'. (n%2) adjust max according to odd or even 'n'
	string str(max,' ');
	if(row == 0) return str;
	
	int x = (row <= size-size/2) ? (row-1)*2 - 1 : (size-row)*2 - 1;  // produces -1 1 3...
	if(row == 1 || row == size) x++;    // make it 0 1 3 5 ...
		
	for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	for(int i = max-x-n; i <= max-x; i++) str[i-1] = style;
		
	return str;
}

string L(int size,int row,char style = 'L'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size;
	string str(max,' ');
	if(row == 0) return str;

	if(row < size-n)
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	else 
		for(int i = 1+n-(size-row); i <= max; i++) str[i-1] = style;	
	return str;
}

string M(int size,int row,char style = 'M'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int MidRow = size-(size/2);
	int max = (MidRow*4 - 3) + (n*2);
	string str(max,' ');
	if(row == 0) return str;
	
	int x = (row == MidRow) ? row*2 - 2 + n : row*2 - 1 + n;
	int y = (row <= n) ? n-(row-1) : 0;
	int z = (row >= size-n) ? (size-row) : n;
	if(row >= MidRow-n) n = MidRow-row;
	
	if(row>1){
		for(int i = 1+y; i <= 1+z; i++) str[i-1] = style;
		for(int i = max-z; i <= max-y; i++) str[i-1] = style;
	}
	if(row <= MidRow){ 
		for(int i = 1+x; i <= 1+x+n; i++) str[i-1] = style;
		for(int i = max-x-n; i <= max-x; i++) str[i-1] = style;
	}
	return str;
}

string N(int size,int row,char style = 'N'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = ((size/2+1)*2 + 3) + (n*3);
	string str(max,' ');
	if(row == 0) return str;
	
	int x = (size-1)/2;    //(size-1)/2 gives like 2 2 3 3 4 4
	
	for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	for(int i = max-n; i <= max; i++) str[i-1] = style;
	
	if(row < (size-size/2)-(n/2)) 
		for(int i = 1+row+n; i <= 1+row+(2*n); i++) str[i-1] = style;
	else if(row <= (size/2+1)+(n/2))  
		for(int i = (1+row*2)-x+n; i <= (1+row*2)-x+(2*n); i++) str[i-1] = style;   
	else 
		for(int i = max-1-(size-row)- (2*n); i <= max-1-(size-row)-n; i++) str[i-1] = style;
	return str;
}

string O(int size,int row,char style = 'O'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = (size*2)-1;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n)
		for(int i = 2+n-(row-1); i <= (max-1)-(n-(row-1)); i++) str[i-1] = style;
	else if(row >= size-n)
		for(int i = 2+n+(row-size); i <= (max-1)-n+(size-row); i++) str[i-1] = style;
	else{ 
		for(int i = 1; i <= 2+n; i++) str[i-1] = style;
		for(int i = max-n-1; i <= max; i++) str[i-1] = style;
	}
	return str;
}

string P(int size,int row,char style = 'P'){
	if(size == 11) size--;   // because in size = 11, it looks bad. size-- because at size = 11 , size = size-1.
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	size = size-(size/2);
	int max = size*2 - 1;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n)  
		for(int i = 2+n-row; i <= max-2-n+row; i++) str[i-1] = style;
	else if(row < size-n){
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
		for(int i = max-n; i <= max; i++) str[i-1] = style;
	}
	else if(row <= size)
		for(int i = 1; i <= max-1-n+(size-row); i++) str[i-1] = style;
	else 
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	
	return str;
}

string Q(int size,int row,char style = 'Q'){
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

string R(int size,int row,char style = 'R'){
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

string S(int size,int row,char style = 'S'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = size;
	string str(max,' ');
	if(row == 0) return str;
	
	int x = (size/2+1)+(n/2) - row; // for middle row
	if(row <= 1+n)
		for(int i = 2+n-(row-1); i <= max-n+(row-1); i++) str[i-1] = style;
	else if(row < (size-size/2)-(n/2))
		for(int i = 1; i <= 1+n; i++) str[i-1] = style;
	else if(row <= (size/2+1)+(n/2))
		for(int i = 1+n+(n-x); i <= max-n-x; i++) str[i-1] = style;
	else if(row < size-n)
		for(int i = max-n; i <= max; i++) str[i-1] = style;
	else
		for(int i = 1+n-(size-row); i <= max-1-n+(size-row); i++) str[i-1] = style;
	
	return str;
}

string T(int size,int row,char style = 'T'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = ((size-1)/2)*4 - 1 + (n%2);
	string str(max,' ');
	if(row == 0) return str;
	
	if(row <= 1+n) 
		for(int i = 1; i <= max; i++) str[i-1] = style;
	else
		for(int i = max-(max/2); i <= max/2+1; i++) str[i-1] = style;
	return str;
}

string U(int size,int row,char style = 'U'){
	int n = 1+(size/11);
	int k = size%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = (size*2)-1;
	string str(max,' ');
	if(row == 0) return str;
	
	if(row >= size-n) 
		for(int i = 1+(row-size)+n; i <= max-n+(size-row); i++) str[i-1] = style;
	else{
		for(int i = 1; i <= max; i++) 
			if(i<=1+n || i>=max-n) str[i-1] = style;
	}
	return str;
}

string V(int size,int row,char style = 'V'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - 1;
	string str(max,' ');
	if(row == 0) return str;
	
	if (row >= size-n) n = size-row;
	for(int i = row; i <= row+n; i++) str[i-1] = style;
	for(int i = max-(row-1)-n; i <= max-(row-1); i++) str[i-1] = style;
	return str;
}

string W(int size,int row,char style = 'W'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	size -= n; row -= n;
	int max = (size*2)-1 + n*2;
	string str(max,' ');
	if(row+n == 0) return str;
	
	int x = (row <= 1) ? (row+n-1) : n;            // row+n <= 1+n   --> row <= 1 . since we substracted n from row, we are adding it back to work like usual
	int y = (row >= size-n) ? n-(size-row)+1 : 0;
	for(int i = 1+y; i <= 1+x; i++) str[i-1] = style;
	for(int i = max-x; i <= max-y; i++) str[i-1] = style;
	
	if(row <= n+1) n = row-2;
	int mid = (max/2)+1;
	for(int i = (mid-row+2); i <= (mid-row+2)+n; i++) str[i-1] = style;
	for(int i = (mid+row-2)-n; i <= (mid+row-2); i++) str[i-1] = style;
	
	return str;
}

string X(int size,int row,char style = 'X'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - 3 + n - 2*(n%2);   // n : adjust max according increasing n and 2*(n%2) : adjust max according to odd or even n
	string str(max,' ');
	if(row == 0) return str;
	
	bool m = size%2;
	int x = row - (size/2 + 1);
	if(x < 0) x = -x - (n%2);	
	x = x*2 + max/2 + (n/2);
	if(row%(size-1)==1) x--;
	
	for(int i = max-x; i <= max-x+n; i++) str[i-1] = style;
	for(int i = x+1-n; i <= x+1; i++) str[i-1] = style;
	return str;
}

string Y(int size,int row,char style = 'Y'){
	int n = size/11;
	int k = (size-1)%2;
	if(n%2) k = !k;
	row -= k; size -= k;
	
	int max = (size-(size/2))*4 - 3 + n;
	string str(max,' '); 
	if(row == 0) return str;
	
	int x = row*2 - 2;
	if(row < size-(size/2)){ 
		for(int i = x; i <= x+n; i++) str[i] = style;		
		for(int i = (max-1)-x-n; i <= (max-1)-x; i++) str[i] = style;
	}
	else 
		for(int i = (max-max/2)-(n/2) ; i <= max/2+1+(n/2); i++) str[i-1] = style;
	return str;
}

string Z(int size,int row,char style = 'Z'){
	int n = size/11;
	bool k = (size-1)%2;
	if(n%2) k = !k;
	size -= k; row -= k;
	
	int max = size*2 - 3 - (n*2);
	string str(max,' '); 
	if(row == 0) return str;
	
	int x = (max+1) - (row*2-2) + (n*2);
	if(row <= 1+n || row >= size-n) 
		for(int i = 1; i <= max; i += 2) str[i-1] = style;
	else 
		for(int i = x-(n*2); i <= x; i += 2) str[i-1] = style;
	
	return str;
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











