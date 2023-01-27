#include <stdio.h>
#include "main.h"
#include "esp8266.h"
extern UART_HandleTypeDef huart6;


char Fetch[50];
char Rx_buff[400];
extern int temp;

char * commands[] = {
			/*0*/					"AT\r\n",
			/*1*/					"AT+RST\r\n",
			/*2*/					"AT+CWMODE=3\r\n",
			/*3*/					"AT+CWJAP=\"KM-2.4G\",\"9963111084\"\r\n",
			/*4*/					"AT+CIFSR\r\n",
			/*5*/					"AT+CIPMUX=0\r\n",
			/*6*/					"AT+CIPMODE=0\r\n",
			/*7*/					"AT+CIPSTATUS\r\n",
			/*8*/					"AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n",
			/*9*/					"AT+CIPSEND=40\r\n",
			/*10*/				"AT+CIPCLOSE\r\n"
									};


void WiFi_Init()
{
	At_Cmd();
}
void At_Cmd(void)
{
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT\r\n", 6, 100);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT\r\n", 6, 100);
	}
	At_Reset_Cmd();
}
void At_Reset_Cmd(void)
{
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+RST\r\n", 10, 100);
	HAL_Delay(100);	
/*	while(Check_WiFi_Response()!=0)
	{
		USART6_TX_Outstring("AT+RST\r\n");
	}*/
	At_SetWifi_Mode();
}
void At_SetWifi_Mode(void)
{
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CWMODE=3\r\n", 15, 100);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CWMODE=3\r\n", 15, 100);
	}
	At_Connect_To_Wifi();
}
void At_Connect_To_Wifi(void)
{
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CWJAP=\"KM-2.4G\",\"9963111084\"\r\n", 45, 800);
	HAL_Delay(500);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CWJAP=\"KM-2.4G\",\"9963111084\"\r\n", 45, 800);
		HAL_Delay(1000);
	}
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIFSR\r\n", 12, 100);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIFSR\r\n", 12, 100);
	}
	At_Mux_Mode();
}
void At_Mux_Mode(void)
{
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPMUX=0\r\n", 15, 100);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPMUX=0\r\n", 15, 100);
	}
	At_Mode_Selection();
}
void At_Mode_Selection(void)
{
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPMODE=0\r\n", 16, 100);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPMODE=0\r\n", 16, 100);
	}
}

void WiFi_Transmit(void)
{
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPSTATUS\r\n", 16, 1000);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPSTATUS\r\n", 16, 1000);
	}
	
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n", 44, 1000);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n", 44, 1000);
	}
	
	sprintf(Fetch,"GET /page.php?temp=22&hum=55&dev=10\r\n\r\n");
	
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPSEND=38\r\n", 17, 1000);
	while(Check_WiFi_Response()!=0)
	{
		HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPSEND=40\r\n", 17, 1000);
	}
	
	HAL_UART_Transmit(&huart6, (uint8_t *)Fetch, 43, 1000);
	HAL_Delay(500);
	
	HAL_UART_Transmit(&huart6, (uint8_t *)"AT+CIPCLOSE\r\n", 15, 1000);
	HAL_Delay(500);
}

int Check_WiFi_Response(void)
{
	volatile int i;
	memset((uint8_t *)Rx_buff, 0, sizeof(Rx_buff));
	HAL_UART_Receive(&huart6, (uint8_t *)Rx_buff, 100, 1000);
	for(i=0;i<200;i++)
	{
		if(Rx_buff[i]=='K' && Rx_buff[i-1]=='O')
		{
			return 0;
		}
	}
	return 1;
}
