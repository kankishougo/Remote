#include <stdio.h>
#include <pthread.h>

FILE *rfp = NULL;
FILE *wfp = NULL;

int main(void){

  const char* R_filePath = "C:\\test_r.txt";
  const char* W_filePath = "C:\\test_w.txt";
  FILE *rfp = NULL;
  FILE *wfp = NULL;
  int ret = 0;
  char c;
  
  if(R_filePath = W_filePath){
    return -1;
  }
  
  rfp = fopen("test_r.txt", r);
  wfp = fopen("test_w.txt", w);
  
  if(rfp == NULL){
    printf("failed to fopen():rfp\n");
    return -1;
  }
  
  if(wfp == NULL){
    printf("failed to fopen():wfp\n");
    return -1;
  }
  
  while(fread(&c, sizeof(c), 1, rfp)
  {
    if(fwrite(&c, sizeof(c), 1, wfp){
      ret = 1;
      break;
    }
  }
  
  if(!feof(rfp)){
    ret = 1;
  }
  
  fclose(rfp);
  fclose(wfp);
  
  if(ret == 0){
    printf("Copied %s to %s\n" R_filePath, W_filePath);
  }else{
    printf("Failed to copy %s to %s\n" R_filePath, W_filePath);
  }
  
  getchar();
  
  return 0;
} 
