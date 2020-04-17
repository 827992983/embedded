@running on mini2440

.text
.global _start

_start:
	ldr r0, =0x53000000 @WATCHDOG
	mov r1, #0x0		@Disable WATCHDOG
	str r1, [r0]

	ldr sp, =1024*4	@Init Stack on 1024*4, total 4KB
	bl main
loop:
	b loop
