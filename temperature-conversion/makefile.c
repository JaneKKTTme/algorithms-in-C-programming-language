all : Translatetemperature.exe

Translatetemperature.exe: Translatetemperature.o
				gcc Translatetemperature.o -o Translatetemperature.exe

Translatetemperature.o: Translatetemperature.c
				gcc -c Translatetemperature.c -o Translatetemperature.o

.PHONY : clean
clean:
		-rm all Translatetemperature.o Translatetemperature.exe

