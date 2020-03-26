#Variables
CC = g++
CFLAGS = -g -std=c++11

# Linking all the files

## Intro 
a.exe: swatches.o swatches.h  dlist.h dnode.h    main1.o
	$(CC) $(CFLAGS) swatches.o  dnode.o main1.o -o a.exe

## Conclusion
main1.o: main1.cc swatches.h dnode.h
	$(CC) -c $(CFLAGS) main1.cc -o main1.o