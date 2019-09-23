#ifndef _PARSER_H_
#define _PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



//create structures contain properties for each
typedef struct bus
{
	float idx, v, a, pg, qg, pl, ql, gs, bs,btype;
} bus;

typedef struct branch
{
	float from, to, y, x, charge, ratio, shift;
} branch;
 
typedef struct gen
{
	float idx, bus, mva, x, y, dsr, dtr, dstr, dtc, dstc, qsr, qtr, qstr, qtc, qstc, H, d_0, d_1;
} gen;

typedef struct sw
{
	float sw1, sw2, sw3, sw4, sw5, sw_type, sw7;
} sw; 



//allocate a 2d array dynamically
float **allocate_arr_2_d(int Rows, int Cols)
{    
    //allocate Rows rows, each row is a pointer to floats
    float **array = (float **)malloc(Rows * sizeof(int *)); 
    int row;

    //for each row allocate Cols floats
    for (row = 0; row < Rows; row++) {
        array[row] = (float *)malloc(Cols * sizeof(float));
    }

    return array;
}



//free a 2d array if needed
void free_array(int **array, int Rows) 
{
    int row;

    //first free each row
    for (row = 0; row < Rows; row++) {
         free(array[row]);
    }

    //eventually free the memory of the pointers to the rows
    free(array);
 }



//check the first element of the buf to see if it is space
int check_first_char(char *buffer, int length)
{
	int i;
	for (i = 0; i < length; i++)
        {
        	if(buffer[i] != ' ')
        		break;
        }

    return i;
}



//store floating numbers to a 2d array
float **store_arr_2_d(float **a, char *buffer, int length, int i, int d)
{
	int j;
	int m = 0;
	int k = 0;
	char xTmp[15];

	for (j = d; j < length; j++)
	{
		xTmp[m] = buffer[j];
		m++;

		if (buffer[j] == ' ' && buffer[j+1] != ' ')
		{   
			a[i][k] = atof(xTmp);
			k++;
			m = 0;
	    }
    }

    a[i][k] = atof(xTmp); 

    return a;
}



//assign or set 2d array elements into each struct with different fields
void set_val(bus *bus, branch *branch, gen *gen, sw *sw, float **b, int i)
{
	int a, c, d, e, y, z, w;
	    
	    //assign values to buses paramters
		for (a = 0; a < i; a++)
		{
			int x = 0;

			if (b[a][0] == 9999999.00000)
	        	break;
			
			bus[a].idx = b[a][x++];
			bus[a].v = b[a][x++];
			bus[a].a = b[a][x++];
			bus[a].pg = b[a][x++];
			bus[a].qg = b[a][x++];
			bus[a].pl = b[a][x++];
			bus[a].ql = b[a][x++];
			bus[a].gs = b[a][x++];
			bus[a].bs = b[a][x++];
			bus[a].btype = b[a][x++];
	       
	        //check assignment
	        printf("%.5f %.5f %d\n", bus[a].idx, bus[a].v, i);
	        
	    }
    
        //assign values to branches parameters
	    y = 0;
	    for (c = a + 1; c < i; c++)
	    {
	    	int x = 0;

	    	if (b[c][0] == 9999999.00000)
	        	break;

	    	branch[y].from = b[c][x++];
	    	branch[y].to = b[c][x++];
	    	branch[y].y = b[c][x++];
	    	branch[y].x = b[c][x++];
	    	branch[y].charge = b[c][x++];
	    	branch[y].ratio = b[c][x++];
	    	branch[y].shift = b[c][x++];
	    	
	    	//check assignment
	    	printf("%.5f %.5f %d\n", branch[y].from, branch[y].to, i);
	    	y++;

	    }

	    //assign values to generators parameters
	    z = 0;
	    for (d = c + 1; d < i; d++)
	    {
	    	int x = 0;

	    	if (b[d][0] == 9999999.00000)
	        	break;

	    	gen[z].idx = b[d][x++];
	    	gen[z].bus = b[d][x++];
	    	gen[z].mva = b[d][x++];
	    	gen[z].x = b[d][x++];
	    	gen[z].y = b[d][x++];
	    	gen[z].dsr = b[d][x++];
	    	gen[z].dtr = b[d][x++];
	    	gen[z].dstr = b[d][x++];
	    	gen[z].dtc = b[d][x++];
	    	gen[z].dstc = b[d][x++];
	    	gen[z].qsr = b[d][x++];
	    	gen[z].qtr = b[d][x++];
	    	gen[z].qstc = b[d][x++];
	    	gen[z].qtc = b[d][x++];
	    	gen[z].qstc = b[d][x++];
	    	gen[z].H = b[d][x++];
	    	gen[z].d_0 = b[d][x++];
	    	gen[z].d_1 = b[d][x++];

	    	//check assignment
	    	printf("%.5f %.5f %d\n", gen[z].idx, gen[z].bus, i);
	    	z++;

	    }

        //assign values to switches parameters
	    w = 0;
	    for (e = d + 1; e < i; e++)
	    {
	    	int x = 0;

	    	if (b[e][0] == 9999999.00000)
	        	break;

	    	sw[w].sw1 = b[e][x++];
	    	sw[w].sw2 = b[e][x++];
	    	sw[w].sw3 = b[e][x++];
	    	sw[w].sw4 = b[e][x++];
	    	sw[w].sw5 = b[e][x++];
	    	sw[w].sw_type = b[e][x++];
	    	sw[w].sw7 = b[e][x++];

	    	//check assignment
	    	printf("%.5f %.5f %d\n", sw[w].sw1, sw[w].sw2, i);
	    	w++;

	    } 
}

#endif