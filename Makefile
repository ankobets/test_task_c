CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pthread

all: liblogger.so main

liblogger.so: Logger.cpp Logger.h
	$(CC) $(CFLAGS) -shared -fPIC Logger.cpp -o liblogger.so


main: main.cpp liblogger.so
	$(CC) $(CFLAGS) main.cpp -L. -llogger -o main

clean:
	rm -f liblogger.so main

run: main
	LD_LIBRARY_PATH=. ./main "jurnal.txt" "warn"