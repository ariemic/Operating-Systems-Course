CXX = gcc
CFLAGS = -Wall -g
# -g ułatwia debugowanie skompilowanego kodu

.PHONY: all clean
all:
	$(CXX) $(CFAGS) createProcesses.c -o processes
	$(CXX) $(CFAGS) task2.c -o task2

clean:
	rm -f processes task2
