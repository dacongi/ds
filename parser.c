#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

#define MAX_PER_LINE 99999
#define ROWS 100
#define COLS 100




int main()
{
	char buf[MAX_PER_LINE];  
	FILE *fp;            
	int len;             
	bus bus[10]; 
    branch branch[10];
    gen gen[10];
    sw sw[10];
    int i = 0;

    //check and open input file
	if ((fp = fopen("3g9b.txt", "r")) == NULL)
	{
		perror("fail to read");
		exit(1);
	}

    //allocate a 2d array dynamically
	float **outArr = allocate_arr_2_d(ROWS, COLS);

    //read file line by line
	while (fgets(buf, MAX_PER_LINE, fp) != NULL)
	{
		len = strlen(buf);
		buf[len - 1] = '\0';  
		
		//check the first element of the buf to see if it is space
        int d = check_first_char(buf, len);

        //store floating numbers to 2d array
	    store_arr_2_d(outArr, buf, len, i, d);

		i++;
	}

    //assign values to each struct
    set_val(bus, branch, gen, sw, outArr, i);

    //check assignment
    printf("%.5f %.5f\n", bus[4].pl, branch[8].x);



	return 0;
}
