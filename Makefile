APP = quake
CC = gcc
CFLAGS = -std=c11 -Wall
LIBS = .
SRC_DIR = src

all: $(APP)

$(APP):	src/common.o src/q_stl.o src/sys_linux.o
	$(CC) $(CFLAGS) -I $(LIBS) src/*.o -o src/quake

src/common.o: src/common.c
	$(CC) $(CFLAGS) -I $(LIBS) -c $< -o $@

src/q_stl.o: src/q_stl.c
	$(CC) $(CFLAGS) -I $(LIBS) -c $< -o $@

src/sys_linux.o: src/sys_linux.c
	$(CC) $(CFLAGS) -I $(LIBS) -c $< -o $@

clean:
	rm src/quake
	rm src/*.o
