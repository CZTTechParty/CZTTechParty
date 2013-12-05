#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

static int data_pos;

static ssize_t procfs_read(struct file *filp, char __user *buf, 
        size_t count, loff_t *ppos)
{
        loff_t pos = *ppos;
        char *str = "Hi, World!\n";
        int avail = strlen(str) + 1 - data_pos;

	if (pos < 0)
		return -EINVAL;
	if (pos >= avail)
		return 0;

        if (copy_to_user(buf, str + data_pos, avail)){  
                printk("Error!\n");
                return -EFAULT;
        }

        data_pos += avail;
	return avail;
}

static int procfs_open(struct inode *inode, struct file *file)
{
        data_pos = 0;
        return 0;
}

static const struct file_operations procfs_fops = {
        .owner		= THIS_MODULE,
        .open           = procfs_open,
        .read           = procfs_read,
};

static int __init module_proc_init(void)
{
	if (!proc_create("myproc", 0444, NULL, &procfs_fops))
                return -ENOMEM;
        return 0;
}
 
static void __exit module_proc_fini(void)
{
	remove_proc_entry("myproc", NULL);
	return;
}
 
module_init(module_proc_init);
module_exit(module_proc_fini);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("gaoqunkai@ubuntukylin.com");

