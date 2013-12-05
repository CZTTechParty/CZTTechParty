#include <linux/init.h>
#include <linux/module.h>

static char *name = "Lily";
static int age = 18;
static int age_year[] = {1,2,0};
module_param(name, charp, 0644);
module_param(age, int, 0644);
module_param_array(age_year, int, NULL, 0644);
MODULE_PARM_DESC(name, "default name is Lily.");
MODULE_PARM_DESC(age, "default age is 18.");
MODULE_PARM_DESC(age_year, "default age_year is 1,2.");

static int __init module_hello_init(void)
{
	int i;
	printk(KERN_EMERG "Hello World!\n");
	printk("<0>name:%s\nage:%d\n", name, age);
	for (i = 0; age_year[i] != 0; i ++)
		printk("<0>age_year:%d\n", age_year[i]);

	return 0;
}
 
static void __exit module_hello_fini(void)
{
	printk("<0>Goodbye World!\n");
	return;
}
 
module_init(module_hello_init);
module_exit(module_hello_fini);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("gaoqunkai@ubuntukylin.com");
