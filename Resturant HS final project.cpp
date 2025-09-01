#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

void newline()
{
	cout<<endl<<endl;
}

int code(int x,int y)
{
	return (x * 100 + y);
}


string item_list(int x)
{
    switch(x)
    {
      case 1: return "PIZZA";
	  case 2: return "BURGER";
	  case 3: return "ROLLS";
	  case 4: return "BIRYANI";
	  case 5: return "SANDWICH";
	}
	return 0;
}

string item_names(int x)
{
	switch(x)
	{
		case 101: return "Chilly chicken pizza";
		case 102: return "Chicken BBQ pizza ";
		case 103: return "Peri Peri pizza";
		case 201: return "Ginger Burger";
		case 202: return "Cheese Burger";
		case 301: return "Chicken Chatni Roll";
		case 302: return "Chicken Mayo Roll";
		case 303: return "Veg Roll with fries";
		case 401: return "Chicken Biryani";
		case 402: return "Prawn Biryani";
		case 501: return "Club Sandwich";
		case 502: return "Chicken Crispy Sandwich";
		case 503: return "Extreme Veg Sandwich";
	}
	return 0;
}

void checkout(int prize, int itemcode )
{
	int quantity;
	
	system("cls");
	newline();
	cout<<"\e[7m--> "<<item_names(itemcode)<<"\e[0m";
	newline();
	cout<<"Please Enter Quantity:- "; cin>>quantity;
	
	system("cls");
	cout<<"\e[7m\t\t-----YOUR ORDER-----\e[0m";
	newline();
	cout<<quantity<<" "<<item_names(itemcode)<<endl;
	cout<<"Your Total bill is "<<(prize * quantity);
	newline();
	cout<<"Thank you for ordering from KOCHI RESTAURANT"<<endl;
	
}

void review(string name,char x)
{
	ofstream file1;
	file1.open("Reviews.txt",ios::app);
	file1<<name<<" - "<<x<<endl;
	
	if(x > '2')
	cout<<"Thank you for your ratings.";
	else
	cout<<"Sorry for dissapointing you, will try our best next time.";
}

class pizza
{
    int cost[3][3]={{230,200,150},         // large large large
	                 {170,150,100},         // medium medium medium
 					 {140,120,60 }};        // small small small
					                     
    int choice = 1,size = 1;
    
	public:
		 void interface()
		{
			newline();
			cout<<"Which pizza whould you like?";
			newline();
			
		    for(int i = 1; i <= 3; i++)
			cout<<i<<". "<<item_names(100+i)<<endl;
		    cout<<endl;
			cout<<"Your choice:- "; cin>>choice; 
			
			while(choice < 1 || choice > 3)
			{
				if(cin.fail())
				cin.clear(); cin.sync();
				
			    cout<<"INVALID. Choose correct option(1 - 3): "; 
				cin>>choice;
			}
			
			system("cls");
			newline();
			cout<<"\e[7m-> "<<item_names(100+choice)<<"\e[0m";
			newline();
	        cout<<"1. LARGE RS. " << cost[0][choice-1] <<endl;
	        cout<<"2. MEDIUM RS. "<< cost[1][choice-1]<<endl;
	        cout<<"3. SMALL RS. " << cost[2][choice-1] <<endl;
	        cout<<endl<<"Select the SIZE - ";
	        cin>>size;
	        
	        while(size < 1 || size > 3)
			{
	        	if(cin.fail())
				cin.clear(); cin.sync();
				
				cout<<"INVALID. Choose correct option(1 - 3): "; 
				cin>>size; 
			}
	        
	        
	        checkout(cost[size-1][choice-1] , code(1,choice));
	       	
		}
};

class burger
{
		int cost[2]={180,150};
		int choice;
	public:
		void interface()
		{
			newline();
			
			cout<<"Which Burger whould you like?";
			newline();
			
			for(int i = 1; i <= 2; i++)
			cout<<i<<". "<<item_names(200+i)<<" RS. "<<cost[i-1]<<endl;
		    cout<<endl;
			cout<<"Your choice:- "; cin>>choice;
			
			while(choice < 1 || choice > 2)
			{
				if(cin.fail())
				cin.clear(); cin.sync();
				
				cout<<"INVALID. Choose correct option(1 - 2): "; 
				cin>>choice;
			}
			
	        checkout(cost[choice - 1],code(2,choice));
		}
};

class sandwich
{
	int cost[3]={240,160,100};
	int choice;
	public:
		 void interface()
		{
			newline();
			
			cout<<"Which Sandwich whould you like?";
			
			newline();
			for(int i = 1; i <= 3; i++)
			cout<<i<<". "<<item_names(500+i)<<" RS. "<<cost[i-1]<<endl;
		    cout<<endl;
			cout<<"Your choice:- "; cin>>choice;
			
			while(choice < 1 || choice > 3)
			{
				if(cin.fail())
				cin.clear(); cin.sync();
				
				cout<<"INVALID. Choose correct option(1 - 3): "; 
				cin>>choice;
			}
			
	        checkout(cost[choice - 1],code(5,choice));
	       
		}
};

class roll
{
	int cost[3]={150,100,120};
	int choice;
	public:
		 void interface()
		{
			newline();
			
			cout<<"Which Roll whould you like?";
			
			newline();
			
			for(int i = 1; i <= 3; i++)
			cout<<i<<". "<<item_names(300+i)<<" RS. "<<cost[i-1]<<endl;
			cout<<endl;
			cout<<"Your choice:- "; cin>>choice;
			
			while(choice < 1 || choice > 3)
			{
				if(cin.fail())
				cin.clear(); cin.sync();
				
				cout<<"INVALID. Choose correct option(1 - 3): "; 
				cin>>choice;
			}
			
	        checkout(cost[choice - 1],code(3,choice));
	       
		}
};

class biryani
{
   
    int cost[2][2]={{250,270},{120,140}};
	int choice,size;
	public:
		 void interface()
		{
			newline();
			
			
			cout<<"Which Biryani whould you like?";
			newline();
		    for(int i = 1; i <= 2; i++)
			cout<<i<<". "<<item_names(400+i)<<endl;
		    cout<<endl;
			cout<<"Your choice:- "; cin>>choice;
			
			while(choice < 1 || choice > 2)
			{
				if(cin.fail())
				cin.clear(); cin.sync();
				
				cout<<"INVALID. Choose correct option(1 - 2): "; 
				cin>>choice;
			}
			
			newline();
			system("cls");
			cout<<"\e[7m--> "<<item_names(400+choice)<<"\e[0m";
			newline();
			
	        cout<<"1. FULL RS. "<<(cost[0][choice - 1])<<endl;
	        cout<<"2. HALF RS. "<<(cost[1][choice - 1])<<endl;
	        cout<<"Select the size - ";
	        cin>>size;
	        
	        while(size < 1 || size > 2)
			{
				if(cin.fail())
				cin.clear(); cin.sync();
				
				cout<<"INVALID. Choose correct option(1 - 2): "; cin>>size;
			}
	        
	        checkout((cost[size-1][choice - 1]),code(4,choice));
	       	
		}	
};



class home
{
	char choice;
	pizza piz;
	burger bur;
	sandwich san;
	roll rol;
	biryani bir;
	
	
	public:
		
	home(string name)
	{
		system("cls");
    	cout<<"\e[7m\t\t\t\t\t\t KOCHI RESTAURANT\e[0m";
	    newline();
	    newline();
	    cout<<"Welcome to our Restuarant, "<<name;
	    newline();
	    cout<<"What would you like to order - ";
	    newline();
	    cout<<"-----ITEMS-----";
	    newline();
	
	    for(int i = 1; i <= 5; i++)
	    cout<<i<<". "<<item_list(i)<<endl;
	    cout<<"6. EXIT"<<endl;
	   
	    newline();
	    cout<<"Your choice? : "; 
		cin>>choice;
		cin.sync();
		
		while(choice < '1' || choice > '6')
		{
			cout<<"Enter correct Choice!! -->  ";
			cin>>choice;
			cin.sync();
		}
		
	    switch(choice)
	    	{
        		case '1': piz.interface(); break;
				case '2': bur.interface(); break;
     			case '3': rol.interface(); break;
     			case '4': bir.interface(); break;
       			case '5': san.interface(); break;
       			case '6': exit(0);
				
			}	
	}
};

int main()
{
	cout<<"\e[7m\t\t\t\t\t\t KOCHI RESTAURANT\e[0m";
	newline();
	
	string name;
	char choice;
	choice = 'n';
	cout<<"Enter your name - "; getline(cin,name);

	
	do{
	    home menu(name);    
		cout<<"Would you like order anything else again? Y/N --> "; 
		cin >> choice;
     
        while((choice != 'y' && choice != 'Y') &&  (choice != 'n' && choice != 'N'))
         {
	        cout<<"Invalid. Enter correct Answer (Y/N):- "; 
	        cin>>choice;
	        cin.sync();
         }
         
     }while(choice == 'y' || choice == 'Y');
     
     
     newline();
     
     char rate;
     cout<<"out of 5, how many would you rate us? -  "; cin>>rate;
     while(rate < '1' || rate > '5')
     {
        cout<<"Please rate in the range of (1 - 5) - ";
     	cin>>rate;
     	cin.sync();
	 }
	 
	 review(name,rate);
	 
	return 0;
	
}