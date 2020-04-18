/*
 * init.c: ����һЩ��ʼ��
 */ 

#include "s3c24xx.h"

/*
 * LED1-4��ӦGPB5��GPB6��GPB7��GPB8
 */
#define GPB5_out        (1<<(5*2))      // LED1
#define GPB6_out        (1<<(6*2))      // LED2
#define GPB7_out        (1<<(7*2))      // LED3
#define GPB8_out        (1<<(8*2))      // LED4

/*
 * K1-K4��ӦGPG11��GPG3��GPF2��GPF0
 */
#define GPG11_eint      (2<<(11*2))     // K1,EINT19
#define GPG3_eint       (2<<(3*2))      // K2,EINT11
#define GPF2_eint       (2<<(2*2))      // K3,EINT2
#define GPF0_eint       (2<<(0*2))      // K4,EINT0

 
/*
 * �ر�WATCHDOG������CPU�᲻������
 */
void disable_watch_dog(void)
{
    WTCON = 0;  // �ر�WATCHDOG�ܼ򵥣�������Ĵ���д0����
}

void init_led(void)
{
    GPBCON = GPB5_out | GPB6_out | GPB7_out | GPB8_out ;
}

/*
 * ��ʼ��GPIO����Ϊ�ⲿ�ж�
 * GPIO���������ⲿ�ж�ʱ��Ĭ��Ϊ�͵�ƽ������IRQ��ʽ(��������INTMOD)
 */ 
void init_irq( )
{
    GPFCON  = GPF0_eint | GPF2_eint;
    GPGCON  = GPG3_eint | GPG11_eint;
    
    // ����EINT11��19����Ҫ��EINTMASK�Ĵ�����ʹ������
    EINTMASK &= (~(1<<11)) & (~(1<<19));
        
    /*
     * �趨���ȼ���
     * ARB_SEL0 = 00b, ARB_MODE0 = 0: REQ1 > REQ3����EINT0 > EINT2
     * �ٲ���1��6��������
     * ���գ�
     * EINT0 > EINT2 > EINT11,EINT19����K4 > K3 > K1,K2
     * EINT11��EINT19�����ȼ���ͬ
     */
    PRIORITY = (PRIORITY & ((~0x01) | (0x3<<7))) | (0x0 << 7) ;

    // EINT0��EINT2��EINT8_23ʹ��
    INTMSK   &= (~(1<<0)) & (~(1<<2)) & (~(1<<5));
}




