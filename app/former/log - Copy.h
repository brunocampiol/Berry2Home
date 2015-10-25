#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOG_PATH "cfg/log.txt"

int open_log_file();
int clear_log_file();
int log_warning(char * msg, char * sensor);
int log_info(char * msg, char * sensor);
int log_erro(char * msg, char * sensor);
int log_warning(char * msg);
int log_info(char * msg);
int log_erro(char * msg);
int log_write(char * msg, char * sensor, int cod);
