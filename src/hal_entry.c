#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>

#define LED_PIN    BSP_IO_PORT_02_PIN_09 /* Onboard LED pins */

extern rt_int8_t Value;
extern rt_int8_t ARC_value1;
extern rt_int8_t ARC_value2;
extern rt_int8_t Slider_value1;
extern rt_int8_t Slider_value2;

#define SAMPLE_UART_NAME       "uart4"    /* �����豸���� */
static rt_device_t serial; /* �����豸��� */

char str1[] = "1";
char str2[] = "2";
char str3[] = "3";
char str4[] = "4";

void send_packet(rt_int8_t function_code,rt_int8_t data1,rt_int8_t data2){

    rt_int8_t packet[5];
    packet[0] = 0xAA; // ��ʼ�ֽ�
    packet[1] = function_code; // ������ 01,02,03,04
    packet[2] = data1; // ��λ
    packet[3] = data2; // ʮλ
    packet[4] = 0x55; // �����ֽ�

    // �������ݰ�

    //while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); // �ȴ����ͻ�����Ϊ��
    rt_device_write(serial, 0, packet, (sizeof(packet) - 0));
    //USART_SendData(USART1, packet[i]); // ��������



}

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");

    /* ���Ҵ����豸 */
    serial = rt_device_find(SAMPLE_UART_NAME); //�������ֲ���uart4 �豸
    //��uart4
    rt_device_open(serial, RT_DEVICE_FLAG_RX_NON_BLOCKING | RT_DEVICE_FLAG_TX_BLOCKING);
    // �����豸ʹ��ģʽΪ (�������� ���շ�����) ģʽ

    while (1)
    {

        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);

        if (Value == 1)//λ��ģʽ
        {

            send_packet(Value,ARC_value1,ARC_value2);
            /* �����ַ��� */

        }
        if (Value == 2)//�ٶ�ģʽ
        {
            /* �����ַ��� */
            send_packet(Value,Slider_value1,Slider_value2);
            //rt_thread_mdelay(500);
        }
        if (Value == 3)//����ģʽ
        {
            /* �����ַ��� */
            send_packet(Value,ARC_value1,ARC_value2);
            //rt_thread_mdelay(500);
        }
        if (Value == 4)//�߽�ģʽ
        {
            /* �����ַ��� */
            send_packet(Value,ARC_value1,ARC_value2);
            //rt_thread_mdelay(500);
        }
        Value = 0;

    }
}
