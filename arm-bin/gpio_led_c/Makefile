led_on.bin : start.S  led_on.c
	arm-linux-gcc -g -c -o start.o start.S
	arm-linux-gcc -g -c -o led_on.o led_on.c
	arm-linux-ld -Ttext 0x0000000 -g  start.o led_on.o -o led_on_elf
	arm-linux-objcopy -O binary -S led_on_elf led_on.bin
clean:
	rm -f led_on.bin led_on_elf *.o

