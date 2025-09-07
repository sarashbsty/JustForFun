#include<stdio.h>
#include<string.h>
#include "quine.h" // quine struture

void displayGroups(quine group[] , int variables){
	
	int line = 2+8+2+20+2+20+1;
    char str_line[1000];
	if (line >= sizeof(str_line)) line = sizeof(str_line) - 1; // prevent overflow
	
	memset(str_line, '-', line);
    str_line[line] = '\0';
	
	// separator line at start
	printf("\n%s\n",str_line);
	
	printf("%-2s", "|");
    printf("%-8s%-2s", "Group", "|");
    printf("%-20s%-2s", "MinTerm", "|");
    printf("%-20s%s\n", "Binary", "|");
         
    for (int i = 0; i <= variables; i++) {
        if (group[i].count == 0) continue; // skip empty groups
		
		// separator line before every group
		printf("%s\n",str_line);  
		
        for (int j = 0; j < group[i].count; j++) {
			
			printf("%-2s", "|");
            if (j == 0) 
                printf("%-8d",i) ; // print group number only once
            else 
                printf("%-8s"," ");
			printf("%-2s","|");

            /*
			// print all minterms associated with this binary
            string mintermStr = "";
            for (int k = 0; k < group[i].mintermCount[j]; k++) {
                mintermStr += to_string(group[i].minterms[j][k]);
                if (k < group[i].mintermCount[j] - 1) mintermStr += ","; 
            }
			if(group[i].combined[j] == 0) mintermStr += " (x) ";
			*/
			
            printf("%-20s",group[i].binary[j]);
			printf("%-2s","|");
			printf("%-20s",group[i].binary[j]);
			printf("|\n");
                 
        }        
    }
	
	// separator line at end
    printf("%s\n",str_line);;
}