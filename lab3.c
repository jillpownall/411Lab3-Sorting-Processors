#include<stdio.h>
#include<stdlib.h> 

int getSize (char * s) {
/*  returns size of input string */ 
/*  This function is already complete; you may use it freely. */

    char * t;
    for (t = s; *t != '\0'; t++);
    return t - s;
}

// -------------------------------------
// TODO: Function solutions
//
// See assignment for more detailed 
// information about the purpose and
// operation of the function.
//
// Please remember help is available 
// (TA, LAs, or instructor)
// -------------------------------------

void lab_swap_strings(char* strA, char* strB)
/* Swaps contents of two character arrays (strings) */
{
	char temp;
	int index = 0;
	while(strA[index] != '\0' && strB[index] != '\0') {
		temp = strA[index];
		strA[index] = strB[index];
		strB[index] = temp;
		index++;
	}
	if(strA[index] == '\0' && strB[index] != '\0') {
		strA[index] = strB[index];
		strB[index] = '\0';
		index++;
		while(strB[index] != '\0') {
			strA[index] = strB[index];
			index++;
		}
		strA[index] = '\0';
	} else if(strB[index] == '\0' && strA[index] != '\0') {
		strB[index] = strA[index];
		strA[index] = '\0';
		index++;
		while(strA[index] != '\0') {
			strB[index] = strA[index];
			index++;
		}
		strB[index] = '\0';
	}
}

int lab_str_cmp(char* strA, char* strB){
/* returns               */
/*     1  if strA > strB */
/*     0  if strA = strB */
/*     -1 if strA < strB */
	for(int i = 0; strA[i] != '\0' && strB[i] != '\0'; i++) {
		if(strA[i] < strB[i] || strA[i] == '\0') {
			return -1;
		}
		else if(strA[i] > strB[i] || strB[i] == '\0') {
			return 1;
		}
	}
    return 0;
}

void lab_str_upper(char* str){
/* CAPITALIZES STRING s */
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] >= 97 && str[i] <= 122) {
			str[i] = str[i] - 32;
		}
	}
}

void lab_str_lower(char* str){
/* lowercases string s */
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
	}

}

int main() {

	// Variables from Lab 2.
    char processors[10][100];
    char str_temp[100];
    float costs[10];
    float clockrates[10];
    float cpis[10];
    float executiontimes[10];
	int number_of_processors = 0;
	float temp = 0.0;
	char sortby[100];
	char emphasis[100];


	// Enter in all of the different processors, costs, clock rate and CPI

    printf("Please enter the number of processors [1 to 10]:\n");
    scanf("%d", &number_of_processors );

    for (int i=0; i<number_of_processors; i++ ) {
		printf("Processor Name (no spaces):\n" );
		scanf("%s", processors[i] );
		printf("Processor cost (US dollars):\n" );
		scanf("%f", &costs[i] );
		printf("Processor clock rate (in GHz):\n" );
		scanf("%f", &clockrates[i] );
		printf("Processor average CPI:\n" );
		scanf("%f", &cpis[i] );

		executiontimes[i] = (cpis[i]*(1/clockrates[i]))/100;
    };

    printf("Which value would you like to sort on (from lowest to highest)?\n");
    scanf("%s", sortby);

    

    //sort by price
    if(lab_str_cmp(sortby, "price") == 0) {
   	 for(int i = 0; i < number_of_processors-1; i++){
    	for(int j = 0; j < number_of_processors-i-1; j++) {
    		if(costs[j] > costs[j+1]) {
    			temp = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp;
                
                temp = clockrates[j];
                clockrates[j] = clockrates[j+1];
                clockrates[j+1] = temp;
                
                temp = cpis[j];
                cpis[j] = cpis[j+1];
                cpis[j+1] = temp;
            
                temp = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = temp;
            
            	lab_swap_strings(processors[j], processors[j+1]);
    		}
    	}
	}

    printf("Would you rather place emphasis on values above or below a certain threshold?\n");
    scanf("%s", emphasis);
    float threshold;
    printf("What is the threshold value for your comparison?\n");
    scanf("%f", &threshold);
    for(int i = 0; i < number_of_processors; i++) {
    	if(lab_str_cmp(emphasis, "above") == 0) {
    		if(costs[i] > threshold) {
    			lab_str_upper(processors[i]);
    		}
    		if(costs[i] < threshold || costs[i] == threshold) {
    			lab_str_lower(processors[i]);
    		}
    	}
    	if(lab_str_cmp(emphasis, "below") == 0) {
    		if(costs[i] < threshold) {
    			lab_str_upper(processors[i]);
    		}
    		if(costs[i] > threshold || costs[i] == threshold) {
    			lab_str_lower(processors[i]);
    		}
    	}
    }
    printf("Your emphasized list of processors is...\n");
    for(int i = 0; i < number_of_processors; i++) {
    		printf("%s\n", processors[i]);
    	}
	}


	//sort by clockrate
	if(lab_str_cmp(sortby, "rate") == 0){
		for(int i = 0; i < number_of_processors-1; i++) {
    		for(int j = 0; j < number_of_processors-i-1; j++) {
    			if(clockrates[j] > clockrates[j+1]) {
    			temp = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp;
                
                temp = clockrates[j];
                clockrates[j] = clockrates[j+1];
                clockrates[j+1] = temp;
                
                temp = cpis[j];
                cpis[j] = cpis[j+1];
                cpis[j+1] = temp;
            
                temp = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = temp;
            
            	lab_swap_strings(processors[j], processors[j+1]);
               }
           }
        }

    printf("Would you rather place emphasis on values above or below a certain threshold?\n");
    scanf("%s", emphasis);
    float threshold;
    printf("What is the threshold value for your comparison?\n");
    scanf("%f", &threshold);
    for(int i = 0; i < number_of_processors; i++) {
    	if(lab_str_cmp(emphasis, "above") == 0) {
    		if(clockrates[i] > threshold) {
    			lab_str_upper(processors[i]);
    		}
    		if(clockrates[i] < threshold || clockrates[i] == threshold) {
    			lab_str_lower(processors[i]);
    		}
    	}
    	if(lab_str_cmp(emphasis, "below") == 0) {
    		if(clockrates[i] < threshold) {
    			lab_str_upper(processors[i]);
    		}
    		if(clockrates[i] > threshold || clockrates[i] == threshold) {
    			lab_str_lower(processors[i]);
    		}
    	}
    }
    printf("Your emphasized list of processors is...\n");
    for(int i = 0; i < number_of_processors; i++) {
    		printf("%s\n", processors[i]);
    	}
	}



	//sort by execution time
	if(lab_str_cmp(sortby, "time") == 0){
		for(int i = 0; i < number_of_processors-1; i++) {
    		for(int j = 0; j < number_of_processors-i-1; j++) {
    			if(executiontimes[j] > executiontimes[j+1]) {
    			temp = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp;
                
                temp = clockrates[j];
                clockrates[j] = clockrates[j+1];
                clockrates[j+1] = temp;
                
                temp = cpis[j];
                cpis[j] = cpis[j+1];
                cpis[j+1] = temp;
            
                temp = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = temp;
            
            	lab_swap_strings(processors[j], processors[j+1]);
    		}
    	}
    }

    printf("Would you rather place emphasis on values above or below a certain threshold?\n");
    scanf("%s", emphasis);
    float threshold;
    printf("What is the threshold value for your comparison?\n");
    scanf("%f", &threshold);
    for(int i = 0; i < number_of_processors; i++) {
    	if(lab_str_cmp(emphasis, "above") == 0) {
    		if(executiontimes[i] > threshold) {
    			lab_str_upper(processors[i]);
    		} else if(executiontimes[i] < threshold || executiontimes[i] == threshold) {
    			lab_str_lower(processors[i]);
    		}
    	}
    	if(lab_str_cmp(emphasis, "below") == 0) {
    		if(executiontimes[i] < threshold) {
    			lab_str_upper(processors[i]);
    		} else if(executiontimes[i] > threshold || executiontimes[i] == threshold) {
    			lab_str_lower(processors[i]);
    		}
    	}
    }
    printf("Your emphasized list of processors is...\n");
    	for(int i = 0; i < number_of_processors; i++) {
    		printf("%s\n", processors[i]);
    	}
	}


	//sort by name
	if(lab_str_cmp(sortby, "name") == 0){
	for(int i = 0; i < number_of_processors - 1; i++) {
		for(int j = 0; j < number_of_processors - 1; j++) {
			if(lab_str_cmp(processors[j], processors[j+1]) == 1) {
    			temp = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp;
                
                temp = clockrates[j];
                clockrates[j] = clockrates[j+1];
                clockrates[j+1] = temp;
                
                temp = cpis[j];
                cpis[j] = cpis[j+1];
                cpis[j+1] = temp;
            
                temp = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = temp;
            
            	lab_swap_strings(processors[j], processors[j+1]);
			}
		}
	}
    printf("Would you rather place emphasis on values above or below a certain threshold?\n");
    scanf("%s", emphasis);
    char threshold[100];
    printf("What is the threshold value for your comparison?\n");
    scanf("%s", threshold);

    for(int i = 0; i < number_of_processors; i++) {
    	if(lab_str_cmp(emphasis, "above") == 0) {
    		if(lab_str_cmp(processors[i], threshold) == 1) {
    			lab_str_upper(processors[i]);
    		} else if(lab_str_cmp(processors[i], threshold) == -1 || lab_str_cmp(processors[i], threshold) == 0) {
    			lab_str_lower(processors[i]);
    		}
    	}
    	if(lab_str_cmp(emphasis, "below") == 0) {
    		if(lab_str_cmp(processors[i], threshold) == -1) {
    			lab_str_upper(processors[i]);
    		}
    		if(lab_str_cmp(processors[i], threshold) == 1 || lab_str_cmp(processors[i], threshold) == 0) {
    			lab_str_lower(processors[i]);
    		}
    	}
    }

    printf("Your emphasized list of processors is...\n");
    	for(int i = 0; i < number_of_processors; i++) {
    		printf("%s\n", processors[i]);
    	}

    }

    return 0;

}


