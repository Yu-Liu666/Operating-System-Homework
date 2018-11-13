#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");


int hello_init(void)
{

struct task_struct *task;

for_each_process(task) { 

printk("\nname: %s PID: %d State: %ld\n",task->comm,task->pid,task->state);

}

return 0;
}


void hello_exit(void)
{
printk(KERN_INFO "Uploading Module");
}


module_init(hello_init);

module_exit(hello_exit);

MODULE_AUTHOR("Yu Liu");

