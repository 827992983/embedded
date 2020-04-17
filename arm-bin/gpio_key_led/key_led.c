#define GPBCON      (*(volatile unsigned long *)0x56000010)
#define GPBDAT      (*(volatile unsigned long *)0x56000014)

#define GPGCON      (*(volatile unsigned long *)0x56000060)
#define GPGDAT      (*(volatile unsigned long *)0x56000064)

#define GPB5_out_LED1        (1<<(5*2)) // LED1

#define GPG11_in_KEY1    ~(3<<(11*2)) // KEY1

int main()
{
        unsigned long dwDat;

        GPBCON = GPB5_out_LED1; // set output
        GPGCON = GPG11_in_KEY1; // set key1 interrupt
        
        while(1){
            dwDat = GPGDAT;             // read KEY1 status
        
            if (dwDat & (1<<11))
			{
                GPBDAT |= (1<<5);
			}
            else
			{
                GPBDAT &= ~(1<<5);      // KEY1 press, LED1 is light on
			}
    }

    return 0;
}
