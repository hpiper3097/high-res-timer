CPP = g++
CC = gcc
CFLAGS = -lm

.PHONY: all clean

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: $(BINS)

%: %.o
	@echo "Checking.."
	$(CC) $(CFLAGS) $< -o $@
	
%.o: %.cpp
	@echo "Creating objects.."
	$(CPP) -c $<

%.o: %.c
	@echo "Creating objects.."
	$(CC) -c $<

clean:
	@echo "Cleaning up.."
	rm -rvf *.o $(BINS)
