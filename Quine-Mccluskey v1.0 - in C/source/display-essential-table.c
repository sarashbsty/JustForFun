#include<stdio.h>
#include<string.h>
#include "quine.h" // quine struture

//check for improvemnt
void display_essential_table(const quine *prime , int arr[100][100] , int min_terms[] , int min_count){
	
	printf("    ");
	for(int i=0;i<min_count;i++) 
		printf("%-4d" , min_terms[i]);
	
	for(int i = 0; i < prime->count; i++){
		printf("\n%-2c | " , (char)('A'+i));
		for(int x = 0; x < min_count; x++)
			printf("%-4d" , arr[i][min_terms[x]]);
	}
}