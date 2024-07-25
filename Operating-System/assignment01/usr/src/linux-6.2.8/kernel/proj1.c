#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(proj1call)
{
	printk("COMP0312_OS_PROJ1_2021114818_ChanhoKim: Hello Kernel");
	return 0;

}
