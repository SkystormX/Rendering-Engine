CC := g++
PACKAGES := gl glew glfw3
CFLAGS := -Wall -g $(shell pkg-config $(PACKAGES) --cflags)
LFLAGS := $(shell pkg-config $(PACKAGES) --libs)
TARGET := main

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

fresh: clean all

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o
	
.PHONY: all clean