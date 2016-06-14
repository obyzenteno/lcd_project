/* ###################################################################
**     Filename    : Events.h
**     Project     : lcd_project
**     Processor   : MK64FN1M0VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-06-08, 18:00, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [MK64FN1M0LL12]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void);


/*
** ===================================================================
**     Event       :  myserial_OnError (module Events)
**
**     Component   :  myserial [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void myserial_OnError(void);

/*
** ===================================================================
**     Event       :  myserial_OnRxChar (module Events)
**
**     Component   :  myserial [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void myserial_OnRxChar(void);

/*
** ===================================================================
**     Event       :  myserial_OnTxChar (module Events)
**
**     Component   :  myserial [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void myserial_OnTxChar(void);

/*
** ===================================================================
**     Event       :  myserial_OnFullRxBuf (module Events)
**
**     Component   :  myserial [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void myserial_OnFullRxBuf(void);

/*
** ===================================================================
**     Event       :  myserial_OnFreeTxBuf (module Events)
**
**     Component   :  myserial [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void myserial_OnFreeTxBuf(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
