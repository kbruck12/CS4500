#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

asmlinkage int sys_print_other(int pid) 
{
  
     struct task_struct *task; struct task_struct *par; struct pid *id; //trying struct pid...
     id = find_get_pid(pid); //was having trouble "casting int to pointer" with functions I called..
     if(id==NULL)
  {
    printk(KERN_EMERG "No task found with entered PID, Please try another...");
  }
     else
  {
      task = pid_task(id, PIDTYPE_PID); //finds task via pid...hopefully!
    printk (KERN_EMERG "Pid: [%d]  RUNNING STATE: %d  PROGRAM NAME: %s  START TIME: %llu  VRUNTIME: %llu \n ", task->pid, task->state, task->comm, (unsigned long long)current->se.exec_start, (unsigned long long)current->se.vruntime);
      
     printk (KERN_EMERG "PARENT PROCESSE(S) OF [%d]:  ", task->pid);
   
       for(par = task->parent; par->pid != 0; par = par->parent)
        {
          printk(KERN_EMERG "%s [%d],  ", par->comm, par->pid);

        } 
 }
    return 0;
 }





