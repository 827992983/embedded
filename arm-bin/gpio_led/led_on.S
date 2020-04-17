@running on mini2440
.text
.global _start

_start:
	ldr r0, =0x56000010 @GPBCON Register
	ldr r1, =0x4400 	@light on led1 and led3
	str r1, [r0]

	ldr r0, =0x56000014 @GPBDATA Register
	mov r1, #0x0		@value 0 is light on
	str r1, [r0]

loop:
	b loop
