#include "sys.h"
#include "usart.h"	  
#include "delay.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h" 
#include "communication.h"
#include "DS1302.h"
#include "sys.h"


//�ڳ����ʼ��ʱִ��
void CommunicationInit(void)
{
	uart_init(9600);//TXΪPA9,RXΪPA10,������Ϊ9600
}

void SendMsg(void)
{
	char spare= ':';
	char teamInfo[200]="team member:";//��������Ҫ���͵���Ϣ
	int i=0;
	int j=0;
	DS1302_ReadTime();
	for(;j<7;j++)//7�Ǹ����ݵĳ���
	{
		if(DS1302_Time[j])
		{
			//char one=DS1302_Time[j]%10+'0';
			//char ten=DS1302_Time[j]/10+'0';
			USART_SendData(USART1,DS1302_Time[j]);
			delay_ms(1);//��ֹ���ͻ������������
			//USART_SendData(USART1,one);
			//delay_ms(1);//��ֹ���ͻ������������
		
			//USART_SendData(USART1,spare);
			//delay_ms(1);//��ֹ���ͻ������������
		}
		
	}
	/*
	for(;i<200;i++)
	{
		if(teamInfo[i])
		{
			USART_SendData(USART1,teamInfo[i]);
			delay_ms(1);//��ֹ���ͻ������������
		}
	}*/
}
