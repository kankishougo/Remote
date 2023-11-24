#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>

int main(void)
{
    int ret;
    int mnt_flag = 0;

    ret = mount("/dev/sdb1", "sdb1_image.img", "vfat", mnt_flag,
                "codepage=932,iocharset=utf8");
    if (ret == -1) {
        perror("mount:");
        exit(1);
    }

    printf("mount succeeded\n");
    return 0;
}
