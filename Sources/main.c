/* ###################################################################
**     Filename    : main.c
**     Project     : lcd_project
**     Processor   : MK64FN1M0VLL12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-06-08, 18:00, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "LCD1.h"
#include "RW1.h"
#include "BitIoLdd11.h"
#include "EN1.h"
#include "BitIoLdd1.h"
#include "RS1.h"
#include "BitIoLdd2.h"
#include "DB41.h"
#include "BitIoLdd7.h"
#include "DB51.h"
#include "BitIoLdd8.h"
#include "DB61.h"
#include "BitIoLdd9.h"
#include "DB71.h"
#include "BitIoLdd10.h"
#include "WAIT1.h"
#include "KSDK1.h"
#include "UTIL1.h"
#include "BT1.h"
#include "Serial1.h"
#include "ASerialLdd1.h"
#include "myserial.h"
#include "ASerialLdd2.h"
#include "mywait.h"
#include "GI2C1.h"
#include "CI2C1.h"
#include "WAIT2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "helpincludes.h"
#define MPU 0x68

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  //printf("HOLA MUNDO");
  /* Write your code here */
  /* For example: for(;;) { } */
  byte MPU_PWR=0x6B;
  int16_t AcX,AcY,AcZ,GcX,GcY,GcZ,temp;
  char buffer[15];
  uint8_t aux[15];
  //Inicializando la comunicacion I2C
  GI2C1_Init();
  GI2C1_SelectSlave(MPU);
  GI2C1_WriteByteAddress8(MPU,MPU_PWR,0);
  //Inicializando la comunicacion LCD
  LCD1_UseDisplay(1);
  LCD1_Clear();

    for(;;) {
      //Lectura de los Valores del Acelerometro
	  GI2C1_ReadByteAddress8(MPU,0x3B,&buffer[1]);
	  mywait_Waitms(2);
	  GI2C1_ReadByteAddress8(MPU,0x3C,&buffer[2]);
	  mywait_Waitms(2);
	  AcX=buffer[1];
	  AcX=AcX<<8;
	  AcX=AcX | buffer[2];

	  GI2C1_ReadByteAddress8(MPU,0x3D,&buffer[3]);
	  mywait_Waitms(2);
	  GI2C1_ReadByteAddress8(MPU,0x3E,&buffer[4]);
	  mywait_Waitms(2);
	  AcY=buffer[3];
	  AcY=AcY<<8;
	  AcY=AcY | buffer[4];

      GI2C1_ReadByteAddress8(MPU,0x3F,&buffer[5]);
	  mywait_Waitms(2);
	  GI2C1_ReadByteAddress8(MPU,0x40,&buffer[6]);
	  mywait_Waitms(2);
	  AcZ=buffer[5];
	  AcZ=AcZ<<8;
	  AcZ=AcZ | buffer[6];
	  printf("Acelerometro\nX=%d\tY=%d\tZ=%d\n", AcX,AcY,AcZ);
	  LCD1_WriteLineStr(1,"Acelerometro:   ");
	  UTIL1_Num16sToStr(aux, sizeof(aux), AcX);
	  LCD1_WriteLineStr(2,"                ");
	  LCD1_GotoXY(2,1);
	  LCD1_WriteString("X=");
	  LCD1_GotoXY(2,4);
	  LCD1_WriteString((char*)aux);
	  mywait_Waitms(2000);
	  UTIL1_Num16sToStr(aux, sizeof(aux), AcY);
	  LCD1_WriteLineStr(2,"                ");
	  LCD1_GotoXY(2,1);
	  LCD1_WriteString("Y=");
	  LCD1_GotoXY(2,4);
	  LCD1_WriteString((char*)aux);
	  mywait_Waitms(2000);
	  UTIL1_Num16sToStr(aux, sizeof(aux), AcZ);
	  LCD1_WriteLineStr(2,"                ");
	  LCD1_GotoXY(2,1);
	  LCD1_WriteString("Z=");
	  LCD1_GotoXY(2,4);
	  LCD1_WriteString((char*)aux);
	  mywait_Waitms(2000);

	  //Capturando los valores del Giroscopio
	  GI2C1_ReadByteAddress8(MPU,0x43,&buffer[7]);
	  mywait_Waitms(10);
	  GI2C1_ReadByteAddress8(MPU,0x44,&buffer[8]);
	  mywait_Waitms(10);
	  GcX=buffer[7];
	  GcX=GcX<<8;
	  GcX=GcX | buffer[8];

	  GI2C1_ReadByteAddress8(MPU,0x45,&buffer[9]);
	  mywait_Waitms(10);
	  GI2C1_ReadByteAddress8(MPU,0x46,&buffer[10]);
	  mywait_Waitms(10);
	  GcY=buffer[9];
	  GcY=GcY<<8;
	  GcY=GcY | buffer[10];

	  GI2C1_ReadByteAddress8(MPU,0x47,&buffer[11]);
	  mywait_Waitms(10);
	  GI2C1_ReadByteAddress8(MPU,0x48,&buffer[12]);
	  mywait_Waitms(10);
	  GcZ=buffer[11];
	  GcZ=GcZ<<8;
	  GcZ=GcZ | buffer[12];
	  printf("Giroscopio\nGX=%d\tGY=%d\tGZ=%d\n", GcX,GcY,GcZ);
	  LCD1_WriteLineStr(1,"Giroscopio:     ");
	  UTIL1_Num16sToStr(aux, sizeof(aux), GcX);
	  LCD1_WriteLineStr(2,"                ");
	  LCD1_GotoXY(2,1);
	  LCD1_WriteString("Gx=");
	  LCD1_GotoXY(2,5);
	  LCD1_WriteString((char*)aux);
	  mywait_Waitms(2000);
	  UTIL1_Num16sToStr(aux, sizeof(aux), GcY);
	  LCD1_WriteLineStr(2,"                ");
	  LCD1_GotoXY(2,1);
	  LCD1_WriteString("Gy=");
	  LCD1_GotoXY(2,5);
	  LCD1_WriteString((char*)aux);
	  mywait_Waitms(2000);
	  UTIL1_Num16sToStr(aux, sizeof(aux), GcZ);
	  LCD1_WriteLineStr(2,"                ");
	  LCD1_GotoXY(2,1);
	  LCD1_WriteString("Gz=");
	  LCD1_GotoXY(2,5);
	  LCD1_WriteString((char*)aux);
	  mywait_Waitms(2000);

	  //Capturando los valores de temperatura
	  GI2C1_ReadByteAddress8(MPU,0x41,&buffer[13]);
	  mywait_Waitms(10);
	  GI2C1_ReadByteAddress8(MPU,0x42,&buffer[14]);
	  mywait_Waitms(10);
	  temp=buffer[13];
	  temp=temp<<8;
	  temp=temp | buffer[14];
	  temp=(temp/340)+37;
	  printf("Temperatura = %d\n", temp);
	  LCD1_WriteLineStr(1,"Temperatura:   ");
	  UTIL1_Num16sToStr(aux, sizeof(aux), temp);
	  LCD1_WriteLineStr(2,"                ");
	  LCD1_GotoXY(2,5);
	  LCD1_WriteString((char*)aux);
	  mywait_Waitms(2000);


	  //Recibiendo los datos de GPS del Bluetooth
	  myserial_RecvBlock(btbuffer,sizeof(btbuffer),&rx);
	  strcpy(auxbuffer, btbuffer);
	  char *token;
	  token = strtok(auxbuffer, ",");
	  int i = 0;
	  while(token != NULL)
	  {
		  if(i==0)
		  {
			  if(token==99)
			  {
				  token = NULL;
			  }
		  }
		  if(i == 2){
			printf( "Latitud: %s\n", token );
			LCD1_WriteLineStr(1,"Latitud:   ");
			LCD1_WriteLineStr(2,"                ");
			LCD1_WriteLineStr(2,token);
			mywait_Waitms(2000);
		  }
		  if(i == 3){
			printf( "Longitud: %s\n", token );
			LCD1_WriteLineStr(1,"Longitud:  ");
			LCD1_WriteLineStr(2,"                ");
			LCD1_WriteLineStr(2,token);
			mywait_Waitms(2000);
		  }
		  if(i == 4){
			token=strtok(token,">");
			printf( "Altura: %s\n", token );
			LCD1_WriteLineStr(1,"Altura:    ");
			LCD1_WriteLineStr(2,"                ");
			LCD1_WriteLineStr(2,token);
			mywait_Waitms(2000);
		  }
		  token = strtok(NULL, ",");
		  i++;
	  }
  	  WAIT1_Waitms(1000);
    }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
