$(info Starting make!)

launch.o: launch.c example.h 
	gcc -c launch.c

example.o: example.c example.h
	gcc -c example.c
	
log.o: log.c log.h
	gcc -c log.c

launch: launch.o example.o log.o
	gcc launch.o example.o log.o -o launch


$(info Compilation OK!)