GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = diary
MATRICULA =  20190037518

all: $(PROGRAMA) zip

zip: src/main.cpp src/Diary.cpp src/App.cpp src/Aux.cpp src/Date.cpp src/Time.cpp
	@echo "Compactando em um zip..."
	zip $(MATRICULA).zip src/* include/*

main.o: src/main.cpp
	@echo "Compilando o programa principal..."
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

test.o: src/test.cpp
	@echo "Compilando o teste..."
	$(GCC) $(GCC_FLAGS) -c src/test.cpp

Diary.o: src/Diary.cpp
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Date.o: src/Date.cpp
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

Time.o: src/Time.cpp
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

App.o: src/App.cpp
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Aux.o: src/Aux.cpp
	$(GCC) $(GCC_FLAGS) -c src/Aux.cpp

doc.pdf: messages.md
	pandoc -f markdown -t latex -o doc.pdf

$(PROGRAMA): main.o Diary.o Date.o Time.o App.o Aux.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) main.o Diary.o Date.o Time.o App.o Aux.o

test: main.o Diary.o Date.o Time.o App.o Aux.o test.o
	$(GCC) $(GCC_FLAGS) -o test test.o Diary.o Date.o Time.o App.o Aux.o

.PHONY: all zip