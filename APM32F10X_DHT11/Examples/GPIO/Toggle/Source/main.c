#include "main.h"
#include "dht11.h"
#include "apm32f10x_usart.h"
#include "stdio.h"
  
u8 temperature = 0;  	    
u8 humidity = 0;  

int fputc(int ch, FILE *f)
{
   while (USART_ReadStatusFlag(USART1, USART_FLAG_TXBE) == RESET);
   USART_TxData(USART1, (uint8_t) ch);    
   return ch;
}

void USART_Init(void)
{
    GPIO_Config_T GPIO_ConfigStruct;
    USART_Config_T USART_ConfigStruct;

    RCM_EnableAPB2PeriphClock((RCM_APB2_PERIPH_T)(RCM_APB2_PERIPH_GPIOA | RCM_APB2_PERIPH_USART1));

    GPIO_ConfigStruct.mode = GPIO_MODE_AF_PP;
    GPIO_ConfigStruct.pin = GPIO_PIN_9;
    GPIO_ConfigStruct.speed = GPIO_SPEED_50MHz;
    GPIO_Config(GPIOA, &GPIO_ConfigStruct);

    USART_ConfigStruct.baudRate = 115200;
    USART_ConfigStruct.hardwareFlow = USART_HARDWARE_FLOW_NONE;
    USART_ConfigStruct.mode = USART_MODE_TX;
    USART_ConfigStruct.parity = USART_PARITY_NONE;
    USART_ConfigStruct.stopBits = USART_STOP_BIT_1;
    USART_ConfigStruct.wordLength = USART_WORD_LEN_8B;
    USART_Config(USART1, &USART_ConfigStruct);

    USART_Enable(USART1);
}

int main(void)
{
		USART_Init();
		printf("CLR(0);SBC(0); \r\n");
		while(DHT11_Init())  
    while (1)
    {
				DHT11_Read_Data(&temperature,&humidity);		
				printf("DCV24(10,30,'ÎÂ¶È:%d¡æ',1);DCV24(10,60,'Êª¶È:%d%%',3);\r\n",temperature,humidity);
    }
}
