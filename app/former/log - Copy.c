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

int log_warning(char * msg, char * sensor){
  log_write(msg, sensor, 0, 1);
}

int log_info(char * msg, char * sensor){
  log_write(msg, sensor, 1, 1);
}

int log_erro(char * msg, char * sensor){
  log_write(msg, sensor, 2, 1);
}
int log_warning(char * msg){
  log_write(msg, sensor, 0, 0);
}

int log_info(char * msg){
  log_write(msg, sensor, 1, 0);
}

int log_erro(char * msg){
  log_write(msg, sensor, 2, 0);
}

int log_write(char * msg, char * sensor, int cod, int showSensor){
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

  if(showSensor){
    strcat (buf, " Sensor: ");
    strcat (buf, sensor);
  }

  strcat (buf, " ");
  strcat (buf, c_time_string);

  fputs (buf, log_file);

  printf("%s\n", buf); //debug
	fclose(log_file);
  return 0;
}