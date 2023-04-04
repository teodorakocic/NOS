#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/pid.h>

void my_renice(struct task_struct *task, int priority) 
{	
	struct task_struct *child;
    	struct list_head *list;
    	
    	task->static_prio = priority;
	
	if(priority < 100 || priority > 139) {
		printk("Priority must be in the range [100,139] (mapped to [-20,19])!");
	} else {
		 list_for_each(list, &task->children) {
        		child = list_entry(list, struct task_struct, sibling);
        		my_renice(child, priority);
        	}
	}
}
 

SYSCALL_DEFINE1(identity, int, p_id)
{

	struct pid *pid_struct;
    	struct task_struct *task;
    	int priority = 139;
    
	printk("Starting the syscall!\n");
	printk("Received pid: %d\n", p_id);
    	
    	pid_struct = find_get_pid(p_id);
    	task = pid_task(pid_struct, PIDTYPE_PID);

    	printk("Name of the process: %s with priority before %d\n", task->comm, task->static_prio);
    	my_renice(task, priority);
    	printk("Name of the process: %s with priority after %d\n", task->comm, task->static_prio);
    
    	return 0;
}
