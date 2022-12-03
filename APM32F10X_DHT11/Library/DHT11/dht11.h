#ifndef __DHT11_H
#define __DHT11_H 
#include "apm32f10x_gpio.h" 
#include "apm32f10x_rcm.h"

#define DHT11_RCC  	    RCM_APB2_PERIPH_GPIOB		
#define DHT11_PORT 			GPIOB								
#define DHT11_IO 				GPIO_PIN_9					

void DHT11_IO_OUT (void);								
void DHT11_IO_IN (void);								
void DHT11_RST (void);									

u8 DHT11_Check (void);									
u8 DHT11_Read_Bit (void); 							
u8 DHT11_Read_Byte (void);							
u8 DHT11_Init (void);										
u8 DHT11_Read_Data (u8 *temp, u8 *humi); 		

#endif

