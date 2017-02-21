#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

asmlinkage int sys_print_self (void) 
{
  
     struct task_struct *task; struct task_struct *par;
     for_each_process(task)
 {
       printk (KERN_EMERG "Pid: [%d]  RUNNING STATE: %d  PROGRAM NAME: %s  START TIME: %llu  VRUNTIME: %llu \n ", task->pid, task->state, task->comm, (unsigned long long)current->se.exec_start, (unsigned long long)current->se.vruntime);
      
     printk (KERN_EMERG "PARENT PROCESSE(S) OF [%d]:  ", task->pid);
   
       for(par = task->parent; par->pid != 0; par = par->parent)
        {
          printk(KERN_EMERG "%s [%d],  ", par->comm, par->pid);

        } 
 }
    return 0;
}
  void cleanup_module(void) 
 {
      printk(KERN_EMERG "cleaning up...\n");
 }
