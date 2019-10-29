CPP = g++
CC = gcc
CFLAGS = -lm
IDIR = .
ODIR = obj/

.PHONY: clean

SRCS := $(wildcard *.cpp)
BINS := $(patsubst %.cpp, %.o, $(SRCS))
DEPS = high-res-timer.hpp

main: $(BINS)
	@echo "Checking.."
	$(CPP) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS) 	
	@echo "Creating objects.."
	$(CPP) -c -o $@ $< $(CFLAGS)

#%.o: %.c $(DEPS)
#	@echo "Creating objects.."
#	$(CC) -c $@ $<

clean:
	@echo "Cleaning up.."
	rm -rvf *.o $(BINS)
