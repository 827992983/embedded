all: start.o 
	arm-linux-ld -Tmy_uboot.lds -o my_uboot.elf $^
	arm-linux-objcopy -O binary my_uboot.elf my_uboot.bin
	
%.o : %.S
	arm-linux-gcc -g -c $^
	
%.o : %.c
	arm-linux-gcc -g -c $^
	
.PHONY: clean
clean:
	rm *.o *.elf *.bin


