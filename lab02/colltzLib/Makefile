
CXX = gcc
CFLAGS = -Wall -O0

all: clean static shared ddl

static:
	#create object files
	$(CXX) $(CFLAGS) -c collatz.c
	#create static library
	ar crs libcollatz.a collatz.o
	$(CXX) $(CFLAGS) mainStatic.c -o main_static -L. -l:libcollatz.a
	#-L [sciezka do biblioteki z ktorej plikow chcemy korzstac aby kompilator wiedzial]
	#-l header file/ prototypy uzywanych funkcji?
	#compile main file
	#Musi być -lcollatz lub libcollatz.a lub -l:libcollatz.a
	#opcja -lcollatz mowi ze szukaj w libcollatz.a


shared:
	$(CXX) $(CFLAGS) -c collatz.c
	# -fPIC (position independent code) -share -options for dynamic libraries
	$(CXX) $(CFLAGS) -fPIC -shared -o libcollatz.so collatz.o
	$(CXX) $(CFLAGS) main.c -o main_shared -L. -l:libcollatz.so -Wl,-rpath=.
	#zamist -l:libcollatz.so moze byc -lcollatz
	#zamist -Wl,-rpath,. dziala rowniez -Wl,-rpath=.
	#zamiast -L. oke jest -L./

ddl:
	$(CXX) $(CFLAGS) -c collatz.c
	$(CXX) $(CFLAGS) -fPIC -shared -o libcollatz.so collatz.o
	$(CXX) $(CFLAGS) main.c -o main_dynamic -L. -ldl -D DLL

clean:
	rm -f *.o *.a *.so main_*

