key_led.bin : start.S  key_led.c
	arm-linux-gcc -g -c -o start.o start.S
	arm-linux-gcc -g -c -o key_led.o key_led.c
	arm-linux-ld -Ttext 0x0000000 -g  start.o key_led.o -o key_led_elf
	arm-linux-objcopy -O binary -S key_led_elf key_led.bin
clean:
	rm -f key_led.bin key_led_elf *.o
