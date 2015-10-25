#include "log.h"

FILE *log_file;
char buf[1000];

int open_log_file(){
  log_file = fopen(LOG_PATH, "a");
  if(!log_file) return 1;
  return 0;
}

int clear_log_file(){
  log_file = remove(LOG_PATH);
  if(!log_file) return 1;
  return 0;
}

int log_warning(char * msg){
  log_write(msg, 0);
}

int log_info(char * msg){
  log_write(msg, 1);
}

int log_erro(char * msg){
  log_write(msg, 2);
}
// int log_warning(char * msg){
//   log_write(msg, sensor, 0, 0);
// }
//
// int log_info(char * msg){
//   log_write(msg, sensor, 1, 0);
// }
//
// int log_erro(char * msg){
//   log_write(msg, sensor, 2, 0);
// }

int log_write(char * msg, int cod){
  int x = 0;
  time_t current_time;
  char* c_time_string;
  char* c_tmp;
  /* Obtain current time as seconds elapsed since the Epoch. */
  current_time = time(NULL);
  char * message_type;
  switch (cod) {
    case 0: message_type = "Log.Warning ";
      break;
    case 1: message_type = "Log.Info ";
      break;
    default: message_type = "Log.ERROR ";
      break;
  }

  //if(open_log_file()) return 1; //erro ao abrir arquivo
  open_log_file();
  if (current_time == ((time_t)-1))
  {
      (void) fprintf(stderr, "Failure to compute the current time.\n");
      return 1;
  }

  /* Convert to local time format. */
  c_time_string = ctime(&current_time);

  strcpy (buf, "");
  strcat (buf, message_type);
  strcat (buf, msg);
  strcat (buf, " ");
  strcat (buf, c_time_string);
  fprintf(log_file, "%s\n", buf);
  //fputs (buf, log_file);
	fclose(log_file);
  return 0;

}

int main(void){ //debug

  log_warning("Deu um warning aqui bro");
  log_erro("Deu um erro aqui bro");
  log_info("Deu um info aqui bro");

}
