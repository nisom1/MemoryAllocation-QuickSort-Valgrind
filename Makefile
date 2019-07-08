# You need to write this file so that
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -fprofile-arcs -ftestcoverage
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
DFLAGS = -DTEST_READ -DTEST_WRITE -DTEST_SORTID -DTEST_SORTFIRSTNAME -DTEST_SORTLASTNAME
VALS = valgrind --tool=memcheck --leak-check=full 
GCC = gcc $(CFLAGS) $(DFLAGS) $(VALS) $(COVFLAGS) $(PROFFLAG)

# "make" will create an executable called pa05
all: pa05

# "make test" will run the three input files 
pa05: test1 test2 test3

.c.o:
	$(GCC) $(CFLAGS) $(DFLAGS) -c $*.c 

test: test1 test2 test3 compare

test1: pa05 compare
	echo "testing input file1"
	./pa05 inputs/testinput1 testdir/id1 testdir/first1 testdir/last1 
test2: pa05 compare
	echo "testing input file2"
	./pa05 inputs/testinput2 testdir/id1 testdir/first2 testdir/last2 
test3: pa05 compare
	echo "testing input file3"
	./pa05 inputs/testinput3 testdir/id3 testdir/first3 testdir/last3
# input: inputs/testinput1; output: id1, first1, last1
# input: inputs/testinput2; output: id2, first2, last2
# input: inputs/testinput3; output: id3, first3, last3


# compare your program's output with the expected ouputs by
# using the "diff" command in Linux
compare: 
	diff id1 expected/id1
	diff first1 expected/first1
	diff last1 expected/last1
	diff id2 expected/id2
	diff first2 expected/first2
	diff last2 expected/last2
	diff id3 expected/id3
	diff first3 expected/first3
	diff last3 expected/last3

# "make memory" calls valgrind to check memory errors
memory: pa05
	$(VALS) ./pa05 inputs/testinput1 testdir/id1 testdir/first1 testdir/last1
	$(VALS) ./pa05 inputs/testinput2 testdir/id2 testdir/first2 testdir/last2
	$(VALS) ./pa05 inputs/testinput3 testdir/id3 testdir/first3 testdir/last3
 

pa05.o: pa05.c student.h
	$(GCC) $(DFLAGS) -c pa05.c

student.o: student.c 
	$(GCC) $(VALS) -c student.c

testdir: 
	mkdir -p testdir

# "make clean" remove .o and all output files
clean: 
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
