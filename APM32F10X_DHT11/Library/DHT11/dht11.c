#include "dht11.h"

void Delay_us(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=10;  
      while(i--) ;    
   }
}

void Delay_ms(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=12000;  
      while(i--) ;    
   }
}

void DHT11_IO_OUT (void){ 
    GPIO_Config_T  configStruct;
    configStruct.pin = DHT11_IO;                    
    configStruct.mode = GPIO_MODE_OUT_PP; 
    configStruct.speed = GPIO_SPEED_50MHz; 
    GPIO_Config(DHT11_PORT, &configStruct);
}

void DHT11_IO_IN (void){ 
	  GPIO_Config_T  configStruct;
    configStruct.pin = DHT11_IO;                       
    configStruct.mode = GPIO_MODE_IN_FLOATING; 
	  configStruct.speed = GPIO_SPEED_50MHz; 
    GPIO_Config(DHT11_PORT, &configStruct);
}

void DHT11_RST (void){ 						
	DHT11_IO_OUT();							
	GPIO_ResetBit(DHT11_PORT,DHT11_IO); 	
	Delay_ms(20); 							
	GPIO_SetBit(DHT11_PORT,DHT11_IO); 					
	Delay_us(30); 						
}

u8 DHT11_Check(void){ 	
    u8 retry=0;			
    DHT11_IO_IN();		

	while ((GPIO_ReadInputBit(DHT11_PORT,DHT11_IO) == 1) && retry<100)	
	{
		retry++;
        Delay_us(1);
    }
    if(retry>=100)return 1; 	
	else retry=0;
    while ((GPIO_ReadInputBit(DHT11_PORT,DHT11_IO) == 0) && retry<100)  
	{  
        retry++;
        Delay_us(1);
    }
    if(retry>=100)return 1;	    
    return 0;
}

u8 DHT11_Init (void){	
	RCM_EnableAPB2PeriphClock(DHT11_RCC);	
	DHT11_RST();								
	return DHT11_Check(); 					
}

u8 DHT11_Read_Bit(void)
{
    u8 retry = 0;
    while((GPIO_ReadInputBit(DHT11_PORT,DHT11_IO) == 1) && retry < 100) 
    {
        retry++;
        Delay_us(1);
    }
    retry = 0;
    while((GPIO_ReadInputBit(DHT11_PORT,DHT11_IO) == 0) && retry < 100) 
    {
        retry++;
        Delay_us(1);
    }
    Delay_us(40);
    if(GPIO_ReadInputBit(DHT11_PORT,DHT11_IO) == 1)       
        return 1;
    else
        return 0;
}


u8 DHT11_Read_Byte(void)
{
    u8 i, dat;
    dat = 0;
    for (i = 0; i < 8; i++)
    {
        dat <<= 1;					
        dat |= DHT11_Read_Bit();	
    }
    return dat;
}


u8 DHT11_Read_Data(u8 *temp, u8 *humi)
{
    u8 buf[5];
    u8 i;
    DHT11_RST();						
    if(DHT11_Check() == 0)				
    {
        for(i = 0; i < 5; i++) 			
        {
            buf[i] = DHT11_Read_Byte();	
        }
        if((buf[0] + buf[1] + buf[2] + buf[3]) == buf[4])	
        {
            *humi = buf[0];				
            *temp = buf[2];				
        }
    }
    else return 1;
    return 0;
}


