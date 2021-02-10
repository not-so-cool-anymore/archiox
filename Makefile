build:
	nasm -f elf32 kernel.asm -o kasm.o
	gcc -m32 -c kernel.c -o kc.o
	ld -m elf_i386 -T linker.ld -o kernel kasm.o kc.o

clean:
	rm kasm.o
	rm kc.o
	rm kernel
	