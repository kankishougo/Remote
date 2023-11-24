#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>

#define FILENAMESIZE 100 //ディスクイメージのファイル名の文字数

int main(void)
{
    char filename[FILESIZENAME]; //ディスクイメージのファイル名のための文字列
    FILE *fp;
    int ret;
    int mnt_flag = 0;
    
    printf("作成するイメージファイル名を入力してください(拡張子は.img)：");
    scanf("%s", filename);
    
    fp = fopen(filename, "w");
    
    if(fp == NULL){
      printf("error\n");
      exit(1);
    }
    
    fclose(fp);

    ret = mount("/dev/sdb1", "filename", "vfat", mnt_flag, "codepage=932,iocharset=utf8");
    
    if (ret == -1) {
        perror("mount:");
        exit(1);
    }

    printf("mount succeeded\n");
    return 0;
}
