// THE LUNCHER

// HOW TO COMPILE:
// make launch

// OPTIONS
// -d			program will run in debug mode

// RUN THIS PROGRAM:
// without  debug:  ./launch
// with  debug:  ./launch -d

// make launch && ./launch

#include <stdio.h>
#include <unistd.h>
#include "example.h"
#include "log.h"

unsigned int m_is_debug = 0;

int main(int argc, char *argv[])
{

	int option;

	// this will allow our program to get -d option in
	// the command line to check for debug
	while ((option = getopt(argc, argv, "d")) != EOF)
	{

		switch(option)
		{
			case 'd':
				m_is_debug = 1;
				break;
			default:
				break;
		}

		// these steps we use to make sure
		// we skip the options we read
		argc -= optind;
		argv += optind;
	}

	display_welcome();

	// Clears the log and instantiate
	// a new instance of it
	clear_log_file();
	if (open_log_file() && m_is_debug)
		fprintf(stderr,"Could not use the Log service\n");

	if (m_is_debug)
	{
		log_info("[Main] Debug enabled");
		fprintf(stderr,"Debug enabled\n");
	}
	else
	{
		log_info("[Main] Debug disabled");
	}
		
	log_warning("Deu um warning aqui bro");
	log_erro("Deu um erro aqui bro");
	log_info("Deu um info aqui bro");

	return 0;
}
