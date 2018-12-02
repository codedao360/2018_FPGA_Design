/*
/*
 * main.c
 *
 *  Created on: Nov 26, 2018
 *      Author: �����e
 */

#include <stdio.h>
#include "xil_printf.h"
#include "xil_io.h"
#include "xparameters.h"
#include "Sorting.h"
#include "ParityGenerator.h"
#include "Arithmetic.h"
#include "djb2.h"

int main(){

	//Prog1
	u32 data_in[8] ;
	u32 data_out[8] ;
	//Prog2
	s32 Ari_A , Ari_B , Ari_unit;
	char Ari_unit_c ;
	s32 Ari_Result ;
	//Prog3
	char Parity_data[4] ;
	u32 Parity_result ;
	//Prog4
	char djb2_data[20] ;
	int length ;
	u32 hash_result ;
	//Prog5
	int sw , value ;
	char color  ;

	while(1){
		/*Program1 Start*/

		printf("Program1 : Sorting Start.\r\n");

		for(int i = 0 ; i < 8 ; i ++)
		{
			printf("Enter the %d-th data:",(i+1));
			scanf("%d", &data_in[i]);
			printf(" %d\r\n", data_in[i]);
		}

		printf("The un-sorted array is : \r\n");

		for(int i = 0 ; i<8 ; i++) printf("%d\r\n", data_in[i]);

		printf("\r\n");

		Sorting(XPAR_SORTING_0_S00_AXI_BASEADDR , data_in , data_out);

		printf("The sorted array is:\r\n");

		for(int i = 0 ; i<8 ; i++) printf("%d\r\n", data_out[i]);

		/*Program1 End*/

		/*Program2 Start*/

		printf("Program2 : Arithmetic Start.\r\n");

		printf("Input A:");
		scanf("%d", &Ari_A);
		printf(" %d\r\n", Ari_A);

		printf("Input compute unit(+/-/*):");
		scanf("%s", &Ari_unit_c);
		printf(" %c\r\n", Ari_unit_c);

		printf("Input B:");
		scanf("%d", &Ari_B);
		printf(" %d\r\n", Ari_B);

		switch(Ari_unit_c){
		case '+' :
			Ari_unit = 0 ;
			break ;
		case '-' :
			Ari_unit = 1 ;
			break ;
		case '*' :
			Ari_unit = 2 ;
			break ;
		}

		Ari_Result = compute(XPAR_ARITHMETIC_0_S00_AXI_BASEADDR , Ari_A , Ari_B , Ari_unit) ;

		printf("%d%c%d=%d\r\n", Ari_A , Ari_unit_c , Ari_B , Ari_Result);

		printf("Program2 End.\r\n");

		/*Program2 End*/

		/*Program3 Start*/

		printf("Program3 : Parity-Generator Start.\r\n");

		printf("Input data:");
		scanf("%s", &Parity_data);
		printf(" %s\r\n", Parity_data);

		Parity_result = parity_test(XPAR_PARITYGENERATOR_0_S00_AXI_BASEADDR, Parity_data[0] , Parity_data[1] , Parity_data[2] , Parity_data[3]);

		printf("The parity bit is %d\r\n", Parity_result);

		printf("Program3 End.\r\n");

		/*Program3 End*/

		/*Program4 Start*/

		printf("Program4 : djb2 Start.\r\n");

		printf("Input data :");
		scanf("%s", &djb2_data);
		printf(" %s\r\n", djb2_data);

		length = 0 ;

		for(int i = 0 ; i < 20 ; i++)
		{
			if(djb2_data[i] != NULL) length ++ ;
			else break ;
		}

		hash_result = djb2(XPAR_DJB2_0_S00_AXI_BASEADDR , djb2_data , length);

		printf("The hash value of %s is : %d .\r\n",djb2_data , hash_result);

		printf("Program4 End.\r\n");

		/*Program4 End*/

		/*Program5 Start*/

		printf("Program5 : PWM controller Start.\r\n");

		printf("Which color do you want to see(a/b/c/d):");
		scanf("%s",&color);
		printf("%c\r\n",color);

		switch(color)
		{
		case 'a':sw = 0x00;
		case 'b':sw = 0x01;
		case 'c':sw = 0x02;
		case 'd':sw = 0x03;
		default : sw = 0x00;
		}

		value = PWM(XPAR_PWM_CTRL_0_S00_AXI_BASEADDR , sw);

		/*Program5 End*/
	}
}



