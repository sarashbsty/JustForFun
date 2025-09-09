#include<string.h>
#include "quine.h" // quine struture
#include "helper.h"

//check for improvemnt

int essential_implicants(const quine *prime , int arr[100][100] , int min_terms[] , int min_count, char result[][100]){
	
	//all zero initialize
	for(int i = 0; i < prime->count; i++)
		for(int x = 0; x < min_count; x++)
			arr[i][min_terms[x]] = 0;
	
	//selective entering one
	for(int i = 0; i < prime->count; i++){
		for(int x = 0; x < prime->mintermCount[i]; x++)
			arr[i][prime->minterms[i][x]] = 1;
	}
	
	//Finding the essential implicant by finding column with only one '1' and the prime implecant in that 1's row
	int count = 0,index, ones;
	for(int i = 0; i < min_count; i++){
		
		ones = 0;
		for(int x = 0; x < prime->count; x++){
			if(arr[x][min_terms[i]] == 1){
				ones++;
				index = x;
			}
		}
		// checking ones is only 1 and duplicates
		int check = is_exist(result, prime->binary[index] , count);
		if(ones == 1 && check == 0)
			strcpy(result[count++] , prime->binary[index]);
	}
	return count;
}