#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOG_PATH "cfg/log.txt"

FILE *log_file;
char buf[1000];

int open_log_file(){
  log_file = fopen(LOG_PATH, "r");
  if(!log_file) return 1;
  return 0;
}

int log_warning(char * msg, char * sensor){
  int x = 0;
  if(open_log_file()) return 1; //erro ao abrir arquivo

  strcpy (buf, "");
  strcat (buf, ctime(time(NULL)));
  strcat (buf, " Log.Warning: ");
  strcat (buf, msg);
  strcat (buf, " Sensor: ");
  strcat (buf, sensor);
  while (fgets(buf, 1000, cfg_file) != NULL) x++;
  fprintf(log_file,"%d\n", x);

	fclose(cfg_file);
  return 0;
}
int log_info(char * msg, char * sensor){

}
int log_erro(char * msg, char * sensor){

}
int main(void){
  log_warning("Deu um warning aqui bro", "TMP01")
}
