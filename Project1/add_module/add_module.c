#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <asm/uaccess.h>
#include <linux/printk.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/pid.h>
#include <linux/string.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Teodora");
MODULE_DESCRIPTION("First project NOS");
MODULE_VERSION("0.02");

static int myint=1;

module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
MODULE_PARM_DESC(myint, "An integer"); 

void process_information(struct task_struct *task) {
	struct task_struct *child;
    	struct list_head *list;
	
	 pr_info("Process: %s, pid: [%d], ptrace: %u, tgid: [%d], priority (schedule): %d, static priority: %d, normaln priority: %d, real time priority: %u, policy: %u, flags: %u, message: %lu.\nTimer properties: timer slack: %llu, utime: %llu, stime: %llu, gtime: %llu.\nTask state: exit state: %d, exit code: %d, exit signal %d\nMemory and context: nvcsw: %lu, nivcsw: %lu, min fault: %lu, swap info: %lu, memory areas: %d, start addr of code: %lu, final addr of code: %lu, total number of pages: %lu.\n", task->comm, task->pid, task->ptrace, task->tgid, task->prio, task->static_prio, task->normal_prio, task->rt_priority, task->policy, task->flags, task->ptrace_message, task->timer_slack_ns, task->utime, task->stime, task->gtime, task->exit_state, task->exit_code, task->exit_signal, task->nvcsw, task->nivcsw, task->min_flt, task->maj_flt, task->active_mm->map_count, task->active_mm->start_code, task->active_mm->end_code, task->active_mm->total_vm);
	 
	 list_for_each(list, &task->children) {
        	child = list_entry(list, struct task_struct, sibling);
        	process_information(child);
    	}     
}

static int __init task_lister_init(void)
{
	struct pid *pid_struct;
    	struct task_struct *task;
    	
    	pr_info(KERN_INFO "Loading new module...\n");
    	
    	pid_struct = find_get_pid(myint);
    	task = pid_task(pid_struct, PIDTYPE_PID);
	
	process_information(task);

	return 0;
}

static void __exit task_lister_exit(void)
{
    pr_info(KERN_INFO "Removing new module from kernel...\n");
}


module_init(task_lister_init);
module_exit(task_lister_exit);
