```bash
static:
	#clean up before you start
	make clear
	#first, .o files
	gcc -Wall -c sayHello.c
	gcc -Wall -c saySomething.c
	#this command creates library:
		#argument lib<libraryName>.a means library file
		#next - all .o files
	ar crs libsay.a sayHello.o saySomething.o
	#let's compile main file with our library:
		#-L<path> option imforms in which directory compiler should search for libarary file
		#-l<libraryName> option is about added library
	gcc -Wall main.c -o main -L. -lsay
	#clean up before you finish
	#rm -f *.o




dynamic:
	make clear
	#as with static library, we need .o files
	gcc -Wall -c sayHello.c
	gcc -Wall -c saySomething.c
	#now, cteate library.
		#-shared -fPIC - options for dynamic library
		#-o lib<libraryName>.so - our l#staticibrary file
		#then - .o files
	gcc -Wall -shared -fPIC -o libsay.so sayHello.o saySomething.o
	#compile everything together
	#"-Wl,-rpath=`pwd`" o -Wl,-rpath=pwd`` oznacza "wpisz bieżący katalog roboczy
	#do ścieżki wyszukiwania bibliotek współdzielonych"
	gcc main.c -Wall -o main -L. -lsay -Wl,-rpath=.
	#clean up!
	rm -f *.o

dll:
	#Oh, three hours wasted... It was the main reason, why this tutorial was made. Enjoy!

	#clean up, .o files
	make clear
	gcc -Wall -c sayHello.c
	gcc -Wall -c saySomething.c
	#create dynamic library
	gcc -Wall -shared -fPIC -o libsay.so sayHello.o saySomething.o
	#and now is the magic. For DLL you need some extra code in main.c file, check it out.
		#-L. - we know it
		#-ldl - for dll library
		#-D DLL - in main.c we can see several "#ifdef DLL" commands.
		#-D option could be understood like: compiler add command "#define DLL" to our main.c file
	gcc -Wall main.c -o main -L. -ldl -D DLL
	#clean up
	rm -f *.o
	#Hurray!

clear:
	rm -f *.o *.a *.so main

```

#### objdump - służy do wyświelania informacji o plikach obiektowych lub binarnych
https://man7.org/linux/man-pages/man1/objdump.1.html

aby znaleźć miejsce występowania funkcji w kodzie biarnych nie można bez pośrednio użyć polecenie grep
gdyż działa ono tylko dla blików tekstowych .txt którym plik binarny/ kod maszynowy nie jest
dlatego

**jest poprawne**
```bash
 objdump -d main_static | grep test_collatz_convergence
```
**nie jest poprawne**
```bash
grep test_collatz_convergence main_static
```

