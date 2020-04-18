/*
 * leds.c: ѭ������4��LED
 * ���ڵڶ����ֳ��򣬴�ʱMMU�ѿ�����ʹ�������ַ
 */ 

#define GPBCON      (*(volatile unsigned long *)0xA0000010)     // �����ַ0x56000010
#define GPBDAT      (*(volatile unsigned long *)0xA0000014)     // �����ַ0x56000014

#define GPB5_out    (1<<(5*2))
#define GPB6_out    (1<<(6*2))
#define GPB7_out    (1<<(7*2))
#define GPB8_out    (1<<(8*2))

/*
 * wait�������ϡ�static inline������ԭ��ģ�
 * ��������ʹ�ñ���leds.cʱ��waitǶ��main�У���������ֻ��mainһ��������
 * ����������ʱ��main�����ĵ�ַ�����������ļ�ָ��������ʱװ�ص�ַ��
 * �������ļ�mmu.lds�У�ָ����leds.o������ʱװ�ص�ַΪ0xB4004000��
 * ������head.S�еġ�ldr pc, =0xB4004000��������ȥִ��main������
 */
static inline void wait(unsigned long dly)
{
    for(; dly > 0; dly--);
}

int main(void)
{
    unsigned long i = 0;
    
    // ��LED1-4��Ӧ��GPB5/6/7/8�ĸ�������Ϊ���
    GPBCON = GPB5_out|GPB6_out|GPB7_out|GPB8_out;       

    while(1){
        wait(30000);
        GPBDAT = (~(i<<5));     // ����i��ֵ������LED1-4
        if(++i == 16)
            i = 0;
    }

    return 0;
}

