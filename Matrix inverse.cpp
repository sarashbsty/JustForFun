#include<iostream>
using namespace std;

class create{
    public:
	  void identity(long double matrix[50][50],int size){
        for(int i = 0; i < size; i++){
		  for (int j = 0; j < size; j++){
		    if(i != j)
		      matrix[i][j] = 0;
			else
		 	  matrix[i][j] = 1;
		  } 
	    }
      }
};

class transformation{
	
	// x - constant row or column
	// i - row
	// j - column
	// k - constant
	
	void one_transform(long double A[50][50], long double I[50][50], int x, int size){
      if(A[x][x] != 1){
	    long double k_one = 1/A[x][x];
	    for( int j = 0 ; j < size; j++){
		  A[x][j] = A[x][j] * k_one;
		  I[x][j] = I[x][j] * k_one;
		}   
	  }
    }

    void zero_transform(long double A[50][50], long double I[50][50], int x, int size){
	  long double k_zero;
	  for(int i = 0;i < size;i++){
	    if(A[i][x] != 0 && i != x ){ //no zero transformation for x row
	      k_zero = -A[i][x];
	 	  for(int j = 0; j < size; j++){  
		    A[i][j] = A[i][j] + (A[x][j] * k_zero);			        
		    I[i][j] = I[i][j] + (I[x][j] * k_zero);
		  }
		}
      }
    }


	public:
	
      void transform(long double A[50][50], long double I[50][50], int size){
        for(int x = 0; x < size; x++){
          one_transform(A,I,x,size);
          zero_transform(A,I,x,size);
        }
      }
};

class interface{
    
	void fraction(long double x){
      long double nume = x;
	  long double deno = 1;
	  while((int)nume/deno != x){
		nume = nume * 10;
		deno = deno * 10;	
	  }
	  for(int i = deno; i > 1; i--){
        if((int)nume % i == 0 && (int)deno % i == 0){
		  nume = nume / i;
		  deno = deno / i;
	    }
      }
	  if(deno < 2)
        cout<<nume;
	  else
	    cout<<nume<<'/'<<deno;
    }

    
	public:
		
	  void fraction_display(long double matrix[50][50],int size){ // doesnt work
        long double num = 0;
	    for( int i = 0; i < size; i++){
		  for( int j = 0; j < size; j++){
            num = matrix[i][j];
            fraction(num);
			cout<<" ";
		  }
		  cout<<endl;
	    }
      }
  
     void display(long double matrix[50][50],int size){
	  for(int i = 0; i < size; i++){
	    for( int j = 0; j < size; j++){
          cout<<"["<<matrix[i][j]<<"]"<<'\t';
		}
		cout<<endl;
	  }
     }

      void input(long double matrix[50][50],int size){
		for(int i= 0; i < size; i++){
		  for( int j = 0; j < size; j++)
		    cin>>matrix[i][j];
	    } 
      }
};

int main()
{
    int choice = 0;
	int n;
	interface i;
	create c;
	transformation t;
	long double A[50][50],ID[50][50];
	
	dada:
	cout<<"Enter the no. of rows or column --> ";
	cin>>n;
	
	c.identity(ID,n);
     
	cout<<"Enter the elements of the matrix --> ";
    i.input(A,n);
    
    t.transform(A,ID,n);

	cout<<"\n   \e[7m The A matrix \e[0m \n";
	i.display(A,n);
	cout<<"\n   \e[7m The I matrix \e[0m \n";
	i.display(ID,n);
	cout<<endl;
	
//	i.fraction_display(ID,n);  doesnt work
//     cout<<endl;

	cout<<"press 1 to restart --> ";
    cin>>choice;
    if(choice  == 1)
        goto dada;
	return 0;
}



