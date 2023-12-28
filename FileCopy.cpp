#include <stdio.h>
#include <pthread.h>

const char R_fileName[FILENAME_MAX] = "indata.dat";
const char W_fileName[FILENAME_MAX] = "otdata.dat";
int ret = 0;
char buf;

void *thread_read(void *arg){
  FILE *rfp = NULL;
  rfp = fopen("indata.dat", "rb");
  if(rfp == NULL){
    printf("failed to fopen():rfp\n");
  }
  fread(&buf, sizeof(buf), 1, rfp);
  return 0;
}
  
void *thread_write(void *arg){
  FILE *wfp = NULL;
  wfp = fopen("otdata.dat", "wb");
  if(wfp == NULL){
    printf("failed to fopen():wfp\n");
  }
  fwrite(&buf, sizeof(buf), 1, wfp);
  return 0;
}

int main(void){
  
  //thread
  pthread_t thread_r;
  pthread_t thread_w;
  pthread_create(&thread_r, NULL, thread_read, NULL);
  pthread_create(&thread_w, NULL, thread_write, NULL);
  
  pthread_join(thread_r, NULL);
  pthread_join(thread_w, NULL);
  //thread
  
  while(fread(&buf, sizeof(buf), 1, rfp) == 1)
  {
    if(fwrite(&buf, sizeof(buf), 1, wfp) < 1){
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
    printf("Copied %s to %s\n" R_fileName, W_fileName);
  }else{
    printf("Failed to copy %s to %s\n" R_fileName, W_fileName);
  }
  
  getchar();
  
  return 0;
} 
