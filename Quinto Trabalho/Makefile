GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = supermercado
MATRICULA =  20190037518

all: $(PROGRAMA) zip

zip: src/main.cpp src/Cliente.cpp src/Estabelecimento.cpp src/Aux.cpp
	@echo "Compactando em um zip..."
	zip $(MATRICULA).zip src/* include/* readme.md estoque.csv fornecedor.csv Makefile

main.o: src/main.cpp
	@echo "Compilando o programa principal..."
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Cliente.o: src/Cliente.cpp include/Cliente.hpp
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.hpp include/Produto.hpp include/Vector_supermercado.hpp
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp

Fornecedor.o: src/Fornecedor.cpp include/Fornecedor.hpp
	$(GCC) $(GCC_FLAGS) -c src/Fornecedor.cpp

Aux.o: src/Aux.cpp include/Aux.hpp
	$(GCC) $(GCC_FLAGS) -c src/Aux.cpp

doc.pdf: messages.md
	pandoc -f markdown -t latex -o doc.pdf

$(PROGRAMA): main.o Estabelecimento.o Cliente.o Aux.o Fornecedor.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o Estabelecimento.o Cliente.o Aux.o Fornecedor.o

clean:
	rm -f *.o
	rm -f *.txt
	rm -f caixa.csv
	rm $(PROGRAMA)

.PHONY: all zip