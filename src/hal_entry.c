#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>

#define LED_PIN    BSP_IO_PORT_02_PIN_09 /* Onboard LED pins */

extern rt_int8_t Value;
extern rt_int8_t ARC_value1;
extern rt_int8_t ARC_value2;
extern rt_int8_t Slider_value1;
extern rt_int8_t Slider_value2;

#define SAMPLE_UART_NAME       "uart4"    /* 串口设备名称 */
static rt_device_t serial; /* 串口设备句柄 */

char str1[] = "1";
char str2[] = "2";
char str3[] = "3";
char str4[] = "4";

void send_packet(rt_int8_t function_code,rt_int8_t data1,rt_int8_t data2){

    rt_int8_t packet[5];
    packet[0] = 0xAA; // 起始字节
    packet[1] = function_code; // 功能码 01,02,03,04
    packet[2] = data1; // 百位
    packet[3] = data2; // 十位
    packet[4] = 0x55; // 结束字节

    // 发送数据包

    //while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); // 等待发送缓冲区为空
    rt_device_write(serial, 0, packet, (sizeof(packet) - 0));
    //USART_SendData(USART1, packet[i]); // 发送数据



}

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");

    /* 查找串口设备 */
    serial = rt_device_find(SAMPLE_UART_NAME); //按照名字查找uart4 设备
    //打开uart4
    rt_device_open(serial, RT_DEVICE_FLAG_RX_NON_BLOCKING | RT_DEVICE_FLAG_TX_BLOCKING);
    // 串口设备使用模式为 (发送阻塞 接收非阻塞) 模式

    while (1)
    {

        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(500);

        if (Value == 1)//位置模式
        {

            send_packet(Value,ARC_value1,ARC_value2);
            /* 发送字符串 */

        }
        if (Value == 2)//速度模式
        {
            /* 发送字符串 */
            send_packet(Value,Slider_value1,Slider_value2);
            //rt_thread_mdelay(500);
        }
        if (Value == 3)//棘轮模式
        {
            /* 发送字符串 */
            send_packet(Value,ARC_value1,ARC_value2);
            //rt_thread_mdelay(500);
        }
        if (Value == 4)//边界模式
        {
            /* 发送字符串 */
            send_packet(Value,ARC_value1,ARC_value2);
            //rt_thread_mdelay(500);
        }
        Value = 0;

    }
}
