// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"
#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>

rt_int8_t Value = 0;
rt_int8_t ARC_value1 = 0;//��λ
rt_int8_t ARC_value2 = 0;//ʮλ

rt_int8_t Slider_value1 = 0;//��λ
rt_int8_t Slider_value2 = 0;//ʮλ

 static void btn1_event_handler(lv_event_t * e)
 {
     lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_VALUE_CHANGED) {
      rt_kprintf("Butten1 on!\n"); //debug��
      Value = 1;
    //  function_code=1;
    //
    //  void send_packet(rt_uint8_t function_code,rt_uint8_t data);
     }
 }

 static void btn2_event_handler(lv_event_t * e)
 {
     lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_VALUE_CHANGED) {
      rt_kprintf("Butten2 on!\n"); //debug��
      Value = 2;
     }
 }

 static void btn3_event_handler(lv_event_t * e)
 {
     lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_VALUE_CHANGED) {
      rt_kprintf("Butten3 on!\n"); //debug��
      Value = 3;
     }
 }

 static void btn4_event_handler(lv_event_t * e)
{
     lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_VALUE_CHANGED) {
      rt_kprintf("Butten4 on!\n"); //debug��
      Value = 4;
     }
}


//static void btn_event_cb(lv_event_t * e) //ui_Button1 λ�û���ť,ʵ�ֵ�� 0��10 ѭ����ʾ
//{
//
//    lv_event_code_t code = lv_event_get_code(e);
//    lv_obj_t * btn1 = lv_event_get_target(e);
//    if(code == LV_EVENT_CLICKED) {
//        static uint8_t cnt = 0;
//        cnt++;
//        if(cnt>10){cnt=0;}
//        /*Get the first child of the button which is the label and change its text*/
//        lv_obj_t * label = lv_obj_get_child(btn1, 0);
//        lv_label_set_text_fmt(label, "%d", cnt);
//    }
//
//
//}

//�ٶȻ���������,û����Ĭ��100
static void slider_event_cb(lv_event_t * e)
{
    uint8_t SpeedNumb = 0;
    //static lv_obj_t * ui_Label6;
    lv_obj_t * ui_Slider1 = lv_event_get_target(e);
    /*Refresh the text*/
    SpeedNumb = lv_slider_get_value(ui_Slider1); //��ǰ�ٶȴ���ֵ
    Slider_value1 = SpeedNumb/100;//��λ
    Slider_value2 = SpeedNumb%100;//ʮλ

    rt_kprintf("%d\n",SpeedNumb); //debug��
    lv_label_set_text_fmt(ui_Label6, "%"LV_PRId32, lv_slider_get_value(ui_Slider1));
}

//ArcԲ�������������������õ���Ƕ�ֵ��Ĭ��360
static void arc_event_cb(lv_event_t * e)
{
    uint16_t AngleNumb = 0;
    lv_obj_t * ui_Arc1 = lv_event_get_target(e);
    /*Refresh the text*/
    AngleNumb = lv_arc_get_value(ui_Arc1); //��ǰ�ٶȴ���ֵ
    ARC_value1 = AngleNumb/100;
    ARC_value2 = AngleNumb%100;
    rt_kprintf("%d\n",AngleNumb); //debug��
    lv_label_set_text_fmt(ui_Label8, "%"LV_PRId32, lv_arc_get_value(ui_Arc1));
}

//����UART����
static void ui_Switch1_event_cb(lv_event_t * e)
{
    if (lv_obj_has_state(ui_Switch1, LV_STATE_CHECKED))
    {
        rt_kprintf("UART on!\n"); //debug��
        lv_obj_set_style_bg_color(ui_Switch1, lv_color_hex(0xea1b1b), LV_STATE_CHECKED | LV_PART_INDICATOR);
    }
    else
    {
        rt_kprintf("UART off!\n"); //debug��
    }
}

//CANͨ�ſ���
static void ui_Switch2_event_cb(lv_event_t * e)
{
    if (lv_obj_has_state(ui_Switch2, LV_STATE_CHECKED))
    {
        rt_kprintf("CAN on!\n"); //debug��
        lv_obj_set_style_bg_color(ui_Switch2, lv_color_hex(0xea1b1b), LV_STATE_CHECKED | LV_PART_INDICATOR);
    }
    else
    {
        rt_kprintf("CAN off!\n"); //debug��
    }
}

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//uart ����
    ui_Switch1 = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_Switch1, 50);
    lv_obj_set_height(ui_Switch1, 25);
    lv_obj_set_x(ui_Switch1, -200);
    lv_obj_set_y(ui_Switch1, -115);
    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Switch1, ui_Switch1_event_cb, LV_EVENT_ALL, NULL);/*Assign a callback to the button*/

///////////////////////////////////////////////////////////////////////////

    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -195);
    lv_obj_set_y(ui_Label1, -85);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Start UART");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//can ����
    ui_Switch2 = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_Switch2, 50);
    lv_obj_set_height(ui_Switch2, 25);
    lv_obj_set_x(ui_Switch2, -90);
    lv_obj_set_y(ui_Switch2, -115);
    lv_obj_set_align(ui_Switch2, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Switch2, ui_Switch2_event_cb, LV_EVENT_ALL, NULL);/*Assign a callback to the button*/

    ui_Label2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -90);
    lv_obj_set_y(ui_Label2, -85);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "CAN");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
////////////////////////////////////////////////////////////////////////////////////////////
///     ��ť1��2��3��4
///
////////////////////////////////////////////////////////////////////////////////////////////


    ui_Button1 = lv_btn_create(ui_Screen1);    //��ui_Screen1����һ��ui_Button1����
    lv_obj_set_width(ui_Button1, 50);    //���ÿ���
    lv_obj_set_height(ui_Button1, 35);    //���ø߶�
    lv_obj_set_x(ui_Button1, -200);    //����x����λ��
    lv_obj_set_y(ui_Button1, -45);    //����y����λ��
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);    //���ö��뷽ʽ
    lv_obj_add_event_cb(ui_Button1, btn1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_CHECKABLE);//ͨ��LV_OBJ_FLAG_CHECKABLE���԰ѱ�����ɫ���

    label1 = lv_label_create(ui_Button1);
    lv_label_set_text(label1, "POS");
    lv_obj_center(label1);


//    lv_obj_add_event_cb(ui_Button1, btn_event_cb, LV_EVENT_ALL, NULL);/*Assign a callback to the button*/
//    lv_obj_t * label = lv_label_create(ui_Button1);          /*Add a label to the button*/
//    lv_label_set_text(label, "POS");                     /*Set the labels text*/
//    lv_obj_center(label);

    ui_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button2, 50);
    lv_obj_set_height(ui_Button2, 35);
    lv_obj_set_x(ui_Button2, -200);
    lv_obj_set_y(ui_Button2, 9);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Button2, btn2_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_CHECKABLE);
    label2 = lv_label_create(ui_Button2);
    lv_label_set_text(label2, "SPE");
    lv_obj_center(label2);

    ui_Button3 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button3, 50);
    lv_obj_set_height(ui_Button3, 35);
    lv_obj_set_x(ui_Button3, -65);
    lv_obj_set_y(ui_Button3, -45);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Button3, btn3_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_CHECKABLE);
    label3 = lv_label_create(ui_Button3);
    lv_label_set_text(label3, "RAT");
    lv_obj_center(label3);

    ui_Button4 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button4, 50);
    lv_obj_set_height(ui_Button4, 35);
    lv_obj_set_x(ui_Button4, -64);
    lv_obj_set_y(ui_Button4, 9);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Button4, btn4_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_CHECKABLE);
    label4 = lv_label_create(ui_Button4);
    lv_label_set_text(label4, "BOU");
    lv_obj_center(label4);




////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
    ui_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, -133);
    lv_obj_set_y(ui_Label3, -45);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Position");

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, -136);
    lv_obj_set_y(ui_Label4, 12);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Speed ");

    ui_Label9 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label9, 4);
    lv_obj_set_y(ui_Label9, -45);
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "Ratchet");

    ui_Label10 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, 10);
    lv_obj_set_y(ui_Label10, 12);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "Boundary");

    //�ƶ��Ļ��������ڿ����ٶ�
    ui_Slider1 = lv_slider_create(ui_Screen1);
    lv_slider_set_value(ui_Slider1, 0, LV_ANIM_OFF);
    if (lv_slider_get_mode(ui_Slider1) == LV_SLIDER_MODE_RANGE)
        lv_slider_set_left_value(ui_Slider1, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Slider1, 260);
    lv_obj_set_height(ui_Slider1, 20);
    lv_obj_set_x(ui_Slider1, -80);
    lv_obj_set_y(ui_Slider1, 63);
    lv_obj_set_align(ui_Slider1, LV_ALIGN_CENTER);
//�¼�
    lv_obj_add_event_cb(ui_Slider1, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL); /*Assign an event function*/

    ui_Label6 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, -118);
    lv_obj_set_y(ui_Label6, 100);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "0");

    ui_Label5 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, -195);
    lv_obj_set_y(ui_Label5, 100);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "Speed:");
//////////////////////////////////////////////////////////////////////////////////
//�Ƕ�Բ��UI
    ui_Arc1 = lv_arc_create(ui_Screen1);
    lv_obj_set_width(ui_Arc1, 150);
    lv_obj_set_height(ui_Arc1, 150);
    lv_obj_set_x(ui_Arc1, 145);
    lv_obj_set_y(ui_Arc1, -50);
    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc1, 0, 360);
    lv_arc_set_value(ui_Arc1, 1);
    lv_arc_set_bg_angles(ui_Arc1, 0, 360);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xFF0000), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label8, 145);
    lv_obj_set_y(ui_Label8, -50);
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "0");
//����һ���¼�
    lv_obj_add_event_cb(ui_Arc1, arc_event_cb, LV_EVENT_VALUE_CHANGED, NULL); /*Assign an event function*/

    /////////////////////////////////////////////////////////////////////
    ui_Label7 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label7, 145);
    lv_obj_set_y(ui_Label7, 51);
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "Angle control");

    lv_obj_add_event_cb(ui_Label7, ui_event_Label7, LV_EVENT_ALL, NULL);

}