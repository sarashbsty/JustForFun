#include<stdio.h>
#include<string.h>
#include "quine.h" // quine struture


void displayGroups(quine group[] , int variables){
	
	int line = 2+5+3+20+3+15+3+8+2;
    char str_line[1000];
	if (line >= sizeof(str_line)) line = sizeof(str_line) - 1; // prevent overflow
	
	memset(str_line, '-', line);
    str_line[line] = '\0';
	
	// separator line at start
	printf("%s\n",str_line);
	
	printf("%-2s", "|");
    printf("%-5s%-3s", "Group", " |");
    printf("%-20s%-3s", "MinTerm", " |");
    printf("%-15s%-3s", "Binary", " |");
	printf("%-8s", "Combined");
	printf("%2s\n", "|");
         
    for (int i = 0; i <= variables; i++) {
        if (group[i].count == 0) continue; // skip empty groups
		
		// separator line before every group
		printf("%s\n",str_line);  
		
        for (int j = 0; j < group[i].count; j++) {
			
			printf("%-2s", "|");
            if (j == 0) 
                printf("%-5d",i) ; // print group number only once
            else 
                printf("%-5s"," ");
			printf("%-3s"," |");

			// print all minterms associated with this binary
            char str[100]; 
			int written , offset = 0 , size = group[i].mintermCount[j];
            for (int k = 0; k < size; k++) {
				int num = group[i].minterms[j][k];
				written = snprintf(str+offset , sizeof(str)-offset , (k < size-1) ? "%d," : "%d" , num);
				offset += written;
            }
			
            printf("%-20s%-3s", str , " |");
			printf("%-15s%-3s", group[i].binary[j] , " |");
			
			if(group[i].combined[j] == 0) printf("%-9s","❌");  // 11 instead of 10, due to unicode
			else printf("%-9s","✅");                           // same
			
			printf("%2s\n" , "|" );
                 
        }        
    }
	
	// separator line at end
    printf("%s\n",str_line);;
}