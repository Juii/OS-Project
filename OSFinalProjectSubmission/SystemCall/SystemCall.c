#include <linux/kernel.h>
#include <linux/vmalloc.h>


/*************************** Edited Part 2  **************************************/ 

struct node
{
    char data;
    struct node *next;
}*head;
 

asmlinkage long sys_buffer(void)
{
int i;
int a[5];
/*char *c;
char *next;
char *buf;

buf = vmalloc(16 * PAGE_SIZE); /* get 16 pages */
/*****
c = buf;
buf->next = vmalloc(16*PAGE_SIZE);
buf = buf->next;
buf->next = vmalloc(16*PAGE_SIZE);
******/

struct node *temp;
    temp=(struct node *)vmalloc(16*PAGE_SIZE);
    head=temp;
    head->next=NULL;
    a[0] = head;
    temp=(struct node *)vmalloc(16*PAGE_SIZE);
	
    temp->next=head;
    head=temp;
    a[1] = head;
    temp=(struct node *)vmalloc(16*PAGE_SIZE);
	
    temp->next=head;
    head=temp;
    a[2] = head;
    temp=(struct node *)vmalloc(16*PAGE_SIZE);
	
    temp->next=head;
    head=temp;

    a[3] = head;	    

    temp=(struct node *)vmalloc(16*PAGE_SIZE);
	
    temp->next=head;
    head=temp;
   
    a[4] = head;



if (!head)
        /* error! failed to allocate memory */
	printk(" failed to allocate memory");

else 
	printk("Memory allocated yup");
/*
 * buf now points to at least a 16*PAGE_SIZE bytes
 * of virtually contiguous block of memory
 */


vfree(head);
return(head) ;


}
