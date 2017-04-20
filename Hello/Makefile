SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))


Hello: $(OBJS)
	g++ -o $@ $^

all:	Hello