#include "log.h"

FILE *log_file;
char buf[1000];
char buf2[200];

int open_log_file(){
  log_file = fopen(LOG_PATH, "a");
  if(!log_file) return 1;
  return 0;
}

int clear_log_file(){
  int err;
  err = remove(LOG_PATH);
  if(!err) return 1;
  return 0;
}

int log_info(char * msg){
  log_write(msg, 0);
}

int log_warning(char * msg){
  log_write(msg, 1);
}

int log_erro(char * msg){
  log_write(msg, 2);
}

int log_write(char * msg, int cod){
  int x = 0;
  time_t current_time;
  char* c_time_string;
  char* c_tmp;
  /* Obtain current time as seconds elapsed since the Epoch. */
  current_time = time(NULL);
  char * message_type;
  switch (cod) {
    case 0: message_type = "[Log.Info] ";
      break;
    case 1: message_type = "[Log.Warning] ";
      break;
    default: message_type = "[Log.ERROR] ";
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
  
  // Here we copy the time from the system
  // and we remove the new line insert by
  // the system in order to display inline
  strcat(buf2, c_time_string);
  buf2[strcspn(buf2, "\n")] = '\0';
  char *memq = malloc(strlen(buf2)+1);
  strcpy (memq, buf2);
   
  strcpy (buf, "");
  strcat (buf, memq);
  strcat (buf, " ");
  strcat (buf, message_type);
  strcat (buf, msg);
  strcat (buf, "\r\n");
  
  buf2[0] = '\0';
  free(memq);
  
  fprintf(log_file, "%s", buf);
  fclose(log_file);
  return 0;
}

// int main(void){ //debug
//
//   log_warning("Deu um warning aqui bro");
//   log_erro("Deu um erro aqui bro");
//   log_info("Deu um info aqui bro");
//   rename_log_file();
//
// }
