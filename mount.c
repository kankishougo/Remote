#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>

int main(void){
    char fname_R[]; = "sdb1_image.img"; //取得するUSBメモリのイメージファイル名のための文字列
    char fname_W[]; = "test.txt"; //USBメモリへ書き込むファイル名
    FILE *fp_r;
    FILE *fp_w;
    int ret;
    int mnt_flag = 0;
    
    fp_r = fopen(fname_R,"r"); //USBメモリのイメージファイル取得
    
    if(fp_r == NULL){
      printf("%s file not open\n",fname_R);
      return -1;
    }else{
      printf("%s file opened\n",fname_R);
    }

    ret = mount("/dev/sdb1", "fname", "vfat", mnt_flag, "codepage=932,iocharset=utf8"); //取得イメージのマウント
    
    if (ret == -1) {
        perror("mount:");
        exit(1);
    }
    
    fclose(fp_r);

    printf("mount succeeded\n");
        
    fp_w = fopen(fname_W,"w"); //書き込むファイル取得
    
    if(fp_w == NULL){
      printf("%s file not open.\n",fname_W);
      return -1;
    }else{
      printf("%s file opened.\n",fname_W);
    }
    
    fprintf(fp_w,"executed a write to a file"); //ファイルを書き込み
    fclose(fp_w);

    return 0;
}
