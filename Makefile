all: bin/pwgen-Output

bin/pwgen-Output: build/src/main.o build/src/utils.o
	g++ -Wall -Werror build/src/main.o build/src/utils.o -o bin/pwgen-Output

build/src/main.o: src/main.cpp src/utils.h
	g++ -Wall -Werror -c src/main.cpp -o build/src/main.o

build/src/utils.o: src/utils.cpp src/utils.h
	g++ -Wall -Werror -c src/utils.cpp -o build/src/utils.o

#test: build/test build/test/tests.cpp
#	g++ -Wall -Werror build/test/*.o build/src/utils.o -o bin/test

test: build/test trash build/src/utils.o
	g++ -o bin/test build/test/tests.cpp

build/test:
	mkdir -p build/test

build/test/tests.cpp: trash
	g++ -o bin/test build/test/tests.cpp

trash: trash2
	cxxtestgen --error-printer -o build/test/tests.cpp test/MyTestSuite.h

trash2:
	sudo apt install cxxtest


clean:

	rm -rf build/src/*.o bin/pwgen-Output bin/test

.PHONY: clean all

run:
	./bin/pwgen-Output

run_test:
	./bin/test
