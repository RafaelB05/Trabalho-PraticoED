all:	funcoes.o main.o
	g++ -o main funcoes.o main.o

pessoa.o:	funcoes.cpp funcoes.hpp	
	g++ -c funcoes.cpp

main.o:: main.cpp funcoes.hpp
	g++ -c main.cpp

clean:
	rm -rf *.0

vai:
	./main