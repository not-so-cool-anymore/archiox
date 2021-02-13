build:
	nasm -f elf32 bootloader.asm -o bootloader.o
	gcc -m32  -ffreestanding -c  kernel/kernel.c -o kc.o
	ld -m elf_i386 -T linker.ld -o archiox bootloader.o kc.o 

clean:
	rm bootloader.o
	rm kc.o
	rm archiox
	