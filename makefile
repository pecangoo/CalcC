
CC = gcc
CFlAGS = # -Wall -Werror -Wextra
CHECKFLAGS = -lm -lcheck
SOURCES_TEST = testing/supertest.c
SOURCES = sources/parcer.c sources/polish_arifmetic.c sources/list.c  sources/in_polish.c testing/run*.c



all: build run

build: clean
	mkdir build
	cd build && qmake  ../sources
	cd sources && make

dvi:
	rm -rf html
	cd sources && doxygen *.c
	cd sources && open html/index.html



dist:
	tar -cf ./Calc.tar ./

install: build
		

uninstall: clean

run: 
	sources/Calc_1.app/Contents/MacOS/Calc_1

clean:
	rm -rf  sources/*.o sources/Calc_1.app .qmake.stash sources/.qmake.stash  sources/*.autosave sources/.DS_Store testing/.DS_Store *.tar
	rm -rf html latex/ sources/latex sources/html build *.tar *.o *.gcno *.gcda core.a test *.info report .DS_Store sources/html Doxyfolder

check:
	cppcheck --enable=all --force  --check-config for details --suppress=missingIncludeSystem sources/*.c ources/parcer.h sources/polish_arifmetic.h sources/list.h  sources/in_polish.h testing/run*.h
	python3 ../materials/linters/cpplint.py --extensions=c sources/*.c testing/*.c
#python3 ../materials/linters/cpplint.py --extensions=cpp sources/*.cpp

tests: clean
#$(CC) $(CFlAGS) -c $(SOURCES)
#ar rcs core.a *.o 
	gcc -c $(SOURCES_TEST)
#gcc --coverage -o test  supertest.o  core.a  -lm -lcheck
	$(CC) $(CFLAGS) --coverage -o test $(SOURCES) supertest.o $(CHECKFLAGS)
	./test

	

#$(CC) $(CFLAGS) --coverage -o $(TESTEXEC)  *.o $(CHECKFLAGS)
#./$(TESTEXEC)

gcov_report: tests
	lcov -t "gcov_calc" -o gcov_calc.info -c -d .
	genhtml -o report gcov_calc.info


push:
	git add --all
	git commit -ms
	git push --all