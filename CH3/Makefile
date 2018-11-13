obj-m := Project2-2.o
kernel_path=/usr/src/linux-headers-$(shell uname -r)
all:
	make -C $(kernel_path) M=$(PWD) modules
clean:
	make -C $(kernel_path) M=$(PWD) clean

