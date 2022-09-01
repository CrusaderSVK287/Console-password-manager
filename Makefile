.DEFAULT_GOAL := release

### VARIABLES ###

#compiler
CC := gcc
#normal flags
CFLAGS := -Wall -lm -std=c11
#debug flags
LDFLAGS := -lgcov --coverage -g -MMD -MP -fprofile-arcs -ftest-coverage

CFILES := src/*.c lib/*.c
OBJECT_FILES := *.o

TEST_CFILES := tests/*.c
TEST_OBJECT_FILES := t_*.o

ARGS?=

### MAIN PROGRAM ###

#builds program into the build folder and runs it
program:
	@make obj
	$(CC) $(OBJECT_FILES) $(CFLAGS) $(LDFLAGS) -o build/build.out
	@echo ---------------
	@./build/build.out $(ARGS)
	@echo ---------------
	@make cleanup

#compiles .c files to object files
obj:
	$(CC) $(CFILES) $(CFLAGS) $(LDFLAGS) -c

#removes all unnecesary temporary files
cleanup:
	@rm *.o -f
	@rm *.gcno -f
	@rm *.gcda -f
	@rm *.gcov -f
	@rm *.d -f


### TEST RELATED ###

#compiles all test .c files to object files
test_obj:
	$(CC) $(TEST_CFILES) $(CFLAGS) $(LDFLAGS) -c

#builds tests and runs them
test:
	@make test_obj
	$(CC) $(TEST_OBJECT_FILES) $(CFLAGS) $(LDFLAGS) -o build/tests.out
	./build/tests.out $(ARGS)
	@make coverage
	@make cleanup

#displays code coverage
coverage:
	@gcov $(TEST_OBJECT_FILES)


### VALGRIND ###

#shortcut for make memory
mem:
	@make memory

#builds and runs program with valgrind
memory:
	@make obj
	$(CC) $(OBJECT_FILES) $(CFLAGS) -o build/build.out
	@make cleanup

#############################################################################################
#																							#
#	   This part contains the make target for release build, without the debug flags		#
#																							#
#############################################################################################

release:
	$(CC) $(CFILES) $(CFLAGS) -c
	$(CC) $(OBJECT_FILES) $(CFLAGS) -o build/Password_manager.out
	@make cleanup --no-print-directory
	@echo " "
	@echo "-------------------------------------------------------------------------"
	@echo "Compilation was successfull. The binary can be found in the build folder"
	@echo "-------------------------------------------------------------------------"
