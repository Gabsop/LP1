FILES = main.o ClientePF.o ClientePJ.o Agencia.o Conta.o
COMPILER = g++
PROGRAM = Banco
GCC_FLAGS = -I include -std=c++11 -Wall

all: $(PROGRAM)

$(PROGRAM): main.o ClientePF.o ClientePJ.o Agencia.o Conta.o
	$(COMPILER) $(GCC_FLAGS) $(FILES) -o $(PROGRAM)

main.o: src/main.cpp include/ClientePF.hpp include/ClientePJ.hpp include/Fila.hpp include/Agencia.hpp include/Conta.hpp
	$(COMPILER) $(GCC_FLAGS) -c src/main.cpp

ClientePF.o: src/ClientePF.cpp include/ClientePF.hpp
	$(COMPILER) $(GCC_FLAGS) -c src/ClientePF.cpp

ClientePJ.o: src/ClientePJ.cpp include/ClientePJ.hpp
	$(COMPILER) $(GCC_FLAGS) -c src/ClientePJ.cpp


Agencia.o: src/Agencia.cpp include/Agencia.hpp
	$(COMPILER) $(GCC_FLAGS) -c src/Agencia.cpp

Conta.o: src/Conta.cpp include/Conta.hpp
	$(COMPILER) $(GCC_FLAGS) -c src/Conta.cpp


.PHONY: clean run

clean:
	rm *.o
	rm $(PROGRAM)

run: Banco
	./$(PROGRAM)