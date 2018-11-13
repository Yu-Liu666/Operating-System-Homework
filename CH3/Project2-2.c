#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/types.h>
#include<linux/slab.h>
#include <linux/sched.h>


void display (struct task_struct *x){
struct list_head *list;
struct task_struct *task;


list_for_each(list, &x->children)
{ 

task = list_entry(list, struct task_struct,sibling);
printk("\nname: %s PID: %d State: %ld\n",task->comm,task->pid,task->state);
display (task);

}

}

MODULE_LICENSE("Dual BSD/GPL");


static int birthday_init(void)
{
display(&init_task);


return 0;
};

static void birthday_exit(void)
{

}

module_init(birthday_init);
module_exit(birthday_exit);

MODULE_AUTHOR("LiuYu");
MODULE_DESCRIPTION("This is a simple example!/n");
MODULE_ALIAS("A simplest example");

