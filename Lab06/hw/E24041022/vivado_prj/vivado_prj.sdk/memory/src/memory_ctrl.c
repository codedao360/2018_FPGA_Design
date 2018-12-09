/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "xil_printf.h"
#include "xil_io.h"
#include "xparameters.h"

void	write_data(u32 address, u32 data);
s8 read_data(u32 address);

int main()
{

    print("Hello World\n\r");
    s8 a[9],b[18];
    write_data(0x00000000, 0x00000001);
    write_data(0x00000001, 0x00000005);
    write_data(0x00000002, 0x00000004);
    write_data(0x00000003, 0x00000003);
    write_data(0x00000004, 0x00000002);
    write_data(0x00000005, 0x00000001);
    write_data(0x00000006, 0x00000004);
    write_data(0x00000007, 0x00000005);
    write_data(0x00000008, 0x00000003);
    write_data(0x00000009, 0x00000002);
    write_data(0x0000000a, 0x00000002);
    write_data(0x0000000b, 0x00000003);
    write_data(0x0000000c, 0x00000005);
    write_data(0x0000000d, 0x00000004);
    write_data(0x0000000e, 0x00000002);
    write_data(0x0000000f, 0x00000001);
    write_data(0x00000010, 0x00000001);
    write_data(0x00000011, 0x00000003);
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x0000000C, 0x00000012);
/*			//plus
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000004, 0x00000003);	//cmd	write
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000001);					//cmd valid
    for(int i=0;i<100;i++);
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000000);
    b[0]=read_data(0x00000000);
    b[1]=read_data(0x00000001);
    b[2]=read_data(0x00000002);
    b[3]=read_data(0x00000003);
    b[4]=read_data(0x00000004);
    b[5]=read_data(0x00000005);
    b[6]=read_data(0x00000006);
    b[7]=read_data(0x00000007);
    b[8]=read_data(0x00000008);
    b[9]=read_data(0x00000009);
    b[10]=read_data(0x0000000a);
    b[11]=read_data(0x0000000b);
    b[12]=read_data(0x0000000c);
    b[13]=read_data(0x0000000d);
    b[14]=read_data(0x0000000e);
    b[15]=read_data(0x0000000f);
    b[16]=read_data(0x00000010);
    b[17]=read_data(0x00000011);

    a[0]=read_data(0x00000015);
    a[1]=read_data(0x00000016);
    a[2]=read_data(0x00000017);
    a[3]=read_data(0x00000018);
    a[4]=read_data(0x00000019);
    a[5]=read_data(0x0000001a);
    a[6]=read_data(0x0000001b);
    a[7]=read_data(0x0000001c);
    a[8]=read_data(0x0000001d);
    printf("in:\n\r");
    printf("   %d",b[0]);
    printf("   %d",b[1]);
    printf("   %d\n\r",b[2]);
    printf("   %d",b[3]);
    printf("   %d",b[4]);
    printf("   %d\n\r",b[5]);
    printf("   %d",b[6]);
    printf("   %d",b[7]);
    printf("   %d\n\r\n\r",b[8]);
    printf("   %d",b[9]);
    printf("   %d",b[10]);
    printf("   %d\n\r",b[11]);
    printf("   %d",b[12]);
    printf("   %d",b[13]);
    printf("   %d\n\r",b[14]);
    printf("   %d",b[15]);
    printf("   %d",b[16]);
    printf("   %d\n\r",b[17]);

    printf("out:\n\r");
    printf("   %d",a[0]);
    printf("   %d",a[1]);
    printf("   %d\n\r",a[2]);
    printf("   %d",a[3]);
    printf("   %d",a[4]);
    printf("   %d\n\r",a[5]);
    printf("   %d",a[6]);
    printf("   %d",a[7]);
    printf("   %d\n\r",a[8]);
    */
 /*    //minus
      Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000004, 0x00000004);	//cmd	write
      Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000001);					//cmd valid
      for(int i=0;i<100;i++);
      Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000000);
      b[0]=read_data(0x00000000);
      b[1]=read_data(0x00000001);
      b[2]=read_data(0x00000002);
      b[3]=read_data(0x00000003);
      b[4]=read_data(0x00000004);
      b[5]=read_data(0x00000005);
      b[6]=read_data(0x00000006);
      b[7]=read_data(0x00000007);
      b[8]=read_data(0x00000008);
      b[9]=read_data(0x00000009);
      b[10]=read_data(0x0000000a);
      b[11]=read_data(0x0000000b);
      b[12]=read_data(0x0000000c);
      b[13]=read_data(0x0000000d);
      b[14]=read_data(0x0000000e);
      b[15]=read_data(0x0000000f);
      b[16]=read_data(0x00000010);
      b[17]=read_data(0x00000011);

      a[0]=read_data(0x00000015);
      a[1]=read_data(0x00000016);
      a[2]=read_data(0x00000017);
      a[3]=read_data(0x00000018);
      a[4]=read_data(0x00000019);
      a[5]=read_data(0x0000001a);
      a[6]=read_data(0x0000001b);
      a[7]=read_data(0x0000001c);
      a[8]=read_data(0x0000001d);
      printf("in:\n\r");
      printf("   %d",b[0]);
      printf("   %d",b[1]);
      printf("   %d\n\r",b[2]);
      printf("   %d",b[3]);
      printf("   %d",b[4]);
      printf("   %d\n\r",b[5]);
      printf("   %d",b[6]);
      printf("   %d",b[7]);
      printf("   %d\n\r\n\r",b[8]);
      printf("   %d",b[9]);
      printf("   %d",b[10]);
      printf("   %d\n\r",b[11]);
      printf("   %d",b[12]);
      printf("   %d",b[13]);
      printf("   %d\n\r",b[14]);
      printf("   %d",b[15]);
      printf("   %d",b[16]);
      printf("   %d\n\r",b[17]);

      printf("out:\n\r");
      printf("   %d",a[0]);
      printf("   %d",a[1]);
      printf("   %d\n\r",a[2]);
      printf("   %d",a[3]);
      printf("   %d",a[4]);
      printf("   %d\n\r",a[5]);
      printf("   %d",a[6]);
      printf("   %d",a[7]);
      printf("   %d\n\r",a[8]);
    */
    /*   //Mult
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000004, 0x00000005);	//cmd	write
         Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000001);					//cmd valid
         for(int i=0;i<100;i++);
         Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000000);
         b[0]=read_data(0x00000000);
         b[1]=read_data(0x00000001);
         b[2]=read_data(0x00000002);
         b[3]=read_data(0x00000003);
         b[4]=read_data(0x00000004);
         b[5]=read_data(0x00000005);
         b[6]=read_data(0x00000006);
         b[7]=read_data(0x00000007);
         b[8]=read_data(0x00000008);
         b[9]=read_data(0x00000009);
         b[10]=read_data(0x0000000a);
         b[11]=read_data(0x0000000b);
         b[12]=read_data(0x0000000c);
         b[13]=read_data(0x0000000d);
         b[14]=read_data(0x0000000e);
         b[15]=read_data(0x0000000f);
         b[16]=read_data(0x00000010);
         b[17]=read_data(0x00000011);

         a[0]=read_data(0x00000015);
         a[1]=read_data(0x00000016);
         a[2]=read_data(0x00000017);
         a[3]=read_data(0x00000018);
         a[4]=read_data(0x00000019);
         a[5]=read_data(0x0000001a);
         a[6]=read_data(0x0000001b);
         a[7]=read_data(0x0000001c);
         a[8]=read_data(0x0000001d);
         printf("in:\n\r");
         printf("   %d",b[0]);
         printf("   %d",b[1]);
         printf("   %d\n\r",b[2]);
         printf("   %d",b[3]);
         printf("   %d",b[4]);
         printf("   %d\n\r",b[5]);
         printf("   %d",b[6]);
         printf("   %d",b[7]);
         printf("   %d\n\r\n\r",b[8]);
         printf("   %d",b[9]);
         printf("   %d",b[10]);
         printf("   %d\n\r",b[11]);
         printf("   %d",b[12]);
         printf("   %d",b[13]);
         printf("   %d\n\r",b[14]);
         printf("   %d",b[15]);
         printf("   %d",b[16]);
         printf("   %d\n\r",b[17]);

         printf("out:\n\r");
         printf("   %d",a[0]);
         printf("   %d",a[1]);
         printf("   %d\n\r",a[2]);
         printf("   %d",a[3]);
         printf("   %d",a[4]);
         printf("   %d\n\r",a[5]);
         printf("   %d",a[6]);
         printf("   %d",a[7]);
         printf("   %d\n\r",a[8]);
*/
/*   //AT
    	  Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000004, 0x00000006);	//cmd	write
          Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000001);					//cmd valid
          for(int i=0;i<100;i++);
          Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000000);
          b[0]=read_data(0x00000000);
          b[1]=read_data(0x00000001);
          b[2]=read_data(0x00000002);
          b[3]=read_data(0x00000003);
          b[4]=read_data(0x00000004);
          b[5]=read_data(0x00000005);
          b[6]=read_data(0x00000006);
          b[7]=read_data(0x00000007);
          b[8]=read_data(0x00000008);
          b[9]=read_data(0x00000009);

          a[0]=read_data(0x00000015);
          a[1]=read_data(0x00000016);
          a[2]=read_data(0x00000017);
          a[3]=read_data(0x00000018);
          a[4]=read_data(0x00000019);
          a[5]=read_data(0x0000001a);
          a[6]=read_data(0x0000001b);
          a[7]=read_data(0x0000001c);
          a[8]=read_data(0x0000001d);
          printf("in:\n\r");
          printf("   %d",b[0]);
          printf("   %d",b[1]);
          printf("   %d\n\r",b[2]);
          printf("   %d",b[3]);
          printf("   %d",b[4]);
          printf("   %d\n\r",b[5]);
          printf("   %d",b[6]);
          printf("   %d",b[7]);
          printf("   %d\n\r\n\r",b[8]);

          printf("out:\n\r");
          printf("   %d",a[0]);
          printf("   %d",a[1]);
          printf("   %d\n\r",a[2]);
          printf("   %d",a[3]);
          printf("   %d",a[4]);
          printf("   %d\n\r",a[5]);
          printf("   %d",a[6]);
          printf("   %d",a[7]);
          printf("   %d\n\r",a[8]);
*/
    	//deter
    	   Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000004, 0x00000007);	//cmd	write
           Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000001);					//cmd valid
           for(int i=0;i<15;i++);
           Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000000);
           b[0]=read_data(0x00000000);
           b[1]=read_data(0x00000001);
           b[2]=read_data(0x00000002);
           b[3]=read_data(0x00000003);
           b[4]=read_data(0x00000004);
           b[5]=read_data(0x00000005);
           b[6]=read_data(0x00000006);
           b[7]=read_data(0x00000007);
           b[8]=read_data(0x00000008);
           b[9]=read_data(0x00000009);

           a[0]=read_data(0x00000015);
           a[1]=read_data(0x00000016);
           a[2]=read_data(0x00000017);
           a[3]=read_data(0x00000018);
           a[4]=read_data(0x00000019);
           a[5]=read_data(0x0000001a);
           a[6]=read_data(0x0000001b);
           a[7]=read_data(0x0000001c);
           a[8]=read_data(0x0000001d);
           printf("in:\n\r");
           printf("   %d",b[0]);
           printf("   %d",b[1]);
           printf("   %d\n\r",b[2]);
           printf("   %d",b[3]);
           printf("   %d",b[4]);
           printf("   %d\n\r",b[5]);
           printf("   %d",b[6]);
           printf("   %d",b[7]);
           printf("   %d\n\r\n\r",b[8]);

           printf("out:\n\r");
           printf("   %d",a[0]);

    return 0;
}

void	write_data(u32 address, u32 data)
{
	u32 ans;

    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000004, 0x00000002);	//cmd	write
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000008, data);			//data_in
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x0000000C, address);		//address
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000001);					//cmd valid
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000000);					//cmd no valid
    ans = 0x00000000;
    while(ans != 0x00000001)
    {
    	ans = Xil_In32(XPAR_BRAM_0_S00_AXI_BASEADDR);					//waiting for cmd done
    }
}

s8 read_data(u32 address)
{
	u32 ans;
	s8 data;

    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000004, 0x00000001);	//cmd	read
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x0000000C, address);		//address
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000001);					//cmd valid
    Xil_Out32(XPAR_BRAM_0_S00_AXI_BASEADDR, 0x00000000);					//cmd no valid
    ans = 0x00000000;
    while(ans != 0x00000001)
    {
    	ans = Xil_In32(XPAR_BRAM_0_S00_AXI_BASEADDR);					//waiting for cmd done
    }
    data = Xil_In32(XPAR_BRAM_0_S00_AXI_BASEADDR + 0x00000004);			//data_out
    return data;
}
