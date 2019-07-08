# You need to write this file so that
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) # $(COVFLAGS) $(PROFFLAG)


# "make" will create an executable called pa05
all: pa05

# "make test" will run the three input files 
pa05: pa05-input1 pa05-input2 pa05-input3

.c.o:
	$(GCC) $(CFLAGS) -c $*.c 

pa05-test1: pa05
	echo "testing input file1"
	./pa05 inputs/testinput1 
pa05-test2: pa05
	echo "testing input file2"
	./pa05 inputs/testinput2 
pa05-test3: pa05
	echo "testing input file3"
	./pa05 inputs/testinput3 
# input: inputs/testinput1; output: id1, first1, last1
# input: inputs/testinput2; output: id2, first2, last2
# input: inputs/testinput3; output: id3, first3, last3


# compare your program's output with the expected ouputs by
# using the "diff" command in Linux
compare: 
	diff first1 expected/first1

# "make memory" calls valgrind to check memory errors
memory: 
	valgrind ./pa05

# "make clean" remove .o and all output files
clean: 
	/bin/rm -f *.o
	/bin/rm -f 

