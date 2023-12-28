#include <stdio.h>
#include <pthread.h>

FILE *rfp = NULL;
FILE *wfp = NULL;

int main(void){
  
  rfp = fopen("test_r.txt", r);
  wfp = fopen("test_w.txt", w);
  
  if(rfp == NULL){
    printf("failed to fopen()\n");
  }
  
  if(wfp == NULL){
    printf("failed to fopen()\n");
  }
