#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

static struct timer_list my_timer;

void panic_hook(unsigned long data)
{
	*(int *)0 = 0;
	return;
}

static int __init module_panic_init(void)
{
        init_timer(&my_timer);
        my_timer.data = 0;
        my_timer.expires = jiffies + 5 * HZ;
        my_timer.function = panic_hook;       
        add_timer(&my_timer);

	printk("insmod ok.\n");
	return 0;
}

static void __exit module_panic_exit(void)
{
	return;
}

module_init(module_panic_init);
module_exit(module_panic_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("gaoqunkai@ubuntukylin.com");
