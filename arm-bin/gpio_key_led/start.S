.text
.global _start
_start:
          	ldr     r0, =0x56000010     @ WATCHDOG Register
            mov     r1, #0x0                     
            str   	r1, [r0]            @ SET 0 for WATCHDOG
            
            ldr     sp, =1024*4         @ set STACK
            bl      main
loop:
            b       loop
