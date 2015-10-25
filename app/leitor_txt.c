#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

#define CFG_PATH "cfg/config.txt"

int main(){
  // char t[] = "TMP01:2000001.00:1\n";
  // decode_line(t, strlen(t)+1);
  open_cfg_file();
  log_warning("Teste de logagem");
}

// void strip(char *s) {
//     char *p2 = s;
//     while(*s != '\0') {
//     	if(*s != '\t' && *s != '\n') {
//     		*p2++ = *s++;
//     	} else {
//     		++s;
//     	}
//     }
//     *p2 = '\0';
// }

int decode_line(char t[], int tam){
  char * pch;
  char sensor[6], tmp[6];
  int mod, porta;
  float value;

  // faz a cópia para um char com tamanho conhecido neste escopo
  // char t[tam];
  // memcpy(t, t2, tam);

  // tokenizer
  pch = strtok(t, ":");

  if (pch != NULL){
    memcpy(sensor, pch, 6);
    printf("Sensor: %s\n", sensor);
    pch = strtok (NULL, ":"); //pega a proxima string
    memcpy(tmp, pch, (size_t)15);
    value = atof(tmp);
    printf("Value: %s; %2.2f\n", tmp, value);
    pch = strtok (NULL, ":");
    memcpy(tmp, pch, (size_t)5);
    mod = atoi(tmp);
    printf("Mod: %s; %d\n", tmp, mod);
  }
  return 0;
}
int open_cfg_file(){
  FILE *cfg_file;
  char buf[1000];
  cfg_file = fopen(CFG_PATH, "r");

  if(!cfg_file) return 1;
  // fgets(buf, 1000, cfg_file);
  while (fgets(buf, 1000, cfg_file) != NULL){
    // strip(buf);
    decode_line(buf, strlen(buf)+1);
    // printf("%s -> %d \n", buf, strlen(buf));
  }

		fclose(cfg_file);
    return 0;
}
