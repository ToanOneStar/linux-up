#include <linux/module.h>
#include <linux/init.h>
#include <linux/access.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("toanhust");
MODULE_VERSION("1.0");

static struct proc_dir_entry *driver_proc = NULL;

static ssize_t driver_read(struct file *file, char __user *user_buffer, size_t count, loff_t *pos)
{
    static int finished = 0;

    if (finished)
    {
        finished = 0;
        return 0;
    }

    finished = 1;
    return simple_read_from_buffer(user_buffer, count, pos, "hello user\n", 11);
}

static ssize_t driver_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *pos)
{
    char user_data[10] = {0};

    if (copy_from_user(user_data, user_buffer, min(count, sizeof(user_data) - 1)))
        return -EFAULT;

    printk(KERN_INFO "user write: %s\n", user_data);
    return count;
}

static struct proc_ops fops = {
    .proc_read = driver_read,
    .proc_write = driver_write,
};

static int __init mydriver_init(void)
{
    printk(KERN_INFO "Hello kernel\n");
    driver_proc = proc_create("mydriver", 0666, NULL, &fops);
    if (!driver_proc)
        return -ENOMEM;

    return 0;
}

static void __exit mydriver_exit(void)
{
    printk(KERN_INFO "Bye kernel\n");
    proc_remove(driver_proc);
}

module_init(mydriver_init);
module_exit(mydriver_exit);
