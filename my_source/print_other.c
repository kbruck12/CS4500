#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

int module_sys_print_other (int pid) 
{
  
     struct task_struct *task; struct task_struct *par;
     task = pid_task(findv_pid(pid), PIDTYPE_PID);

     if(task==NULL)
  {
    printk(KERN_EMERG "No task found with entered PID, Please try another...");
  }
     else
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

asmlinkage sys_print_other(int pid)
{
 module_sys_print_other(pid);
 cleanup_module(void);
 return 1;
}



