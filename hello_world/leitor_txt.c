#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <log.h>

int main(){
  char t[] = "TMP01:200001:1";
  decode_line(t, strlen(t)+1);
}

int decode_line(char t2[], int tam){
//  char t[13] ="TMP01:26.1:1";
  char * pch;
  char sensor[6], tmp[6];
  int mod, porta;
  float value;

  // faz a cópia para um char com tamanho conhecido neste escopo
  char t[tam];
  memcpy(t, t2, tam);

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
  //else{
    char *err;
    memcpy(err, "Erro ao abrir arquivo ", 22);
    memcpy(err, "*sensor.name* ", 14);
    log_error(err);
  //}
  return 0;
}
