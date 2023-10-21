ifndef config
  config=debug
endif

CC=g++ -std=c++23 -Wall -m64
SRC=$(wildcard src/*.cpp) 
OBJ=$(SRC:.cpp=.o)
LINKS=-L sdl/lib
INCLUDE=-I sdl/include -I src/include
CFLAGS=-lmingw32 -lSDL2main -lSDL2

ifeq ($(config),debug)
TARGETDIR = sdl/bin/Debug
TARGET = $(TARGETDIR)/prog.exe
else ifeq ($(config),release)
CC+=-o3
TARGETDIR = sdl/bin/Release
TARGET = $(TARGETDIR)/prog.exe
CFLAGS +=-s 
endif


all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(INCLUDE) $^ $(LINKS) $(CFLAGS)

%.o: %.cpp
	$(CC) -o $@ $(INCLUDE) -c $< $(LINKS) $(CFLAGS)

clean:
	rm src/*.o ${TARGETDIR}/*.exe
