CPP = g++
CC = gcc
CFLAGS = -lm
IDIR = .
ODIR = obj/

.PHONY: clean

SRCS := $(wildcard *.cpp)
_OBJ := $(patsubst %.cpp, %.o, $(SRCS))
OBJ = $(patsubst %.o, $(ODIR)/%.o, $(_OBJ)) 
DEPS = high-res-timer.hpp

main: $(OBJ)
	@echo "Checking.."
	$(CPP) -o $@ $^ $(CFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS) 	
	@echo "Creating objects.."
	$(CPP) -c -o $@ $< $(CFLAGS)

#%.o: %.c $(DEPS)
#	@echo "Creating objects.."
#	$(CC) -c $@ $<

clean:
	@echo "Cleaning up.."
	rm -rvf $(ODIR)/*.o
