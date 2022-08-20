CC := gcc
CFLAGS := -Wall -std=c11 -g -MMD -MP -fprofile-arcs -ftest-coverage
CFILES := src/main.c src/parser.c
OBJECT_FILES := main.o parser.o	
TEST_OBJECT_FILES := t_main.o t_options.o
LDFLAGS := -lgcov --coverage

program:
	@make obj
	$(CC) $(OBJECT_FILES) $(CFLAGS) -o build/build.out
#
#	Program starts here
#
	@echo ---------------
	./build/build.out help
	@echo ---------------
	@make cleanup

obj:
	$(CC) src/main.c $(CFLAGS) $(LDFLAGS) -c
	$(CC) src/parser.c $(CFLAGS) $(LDFLAGS) -c

cleanup:
	@rm *.o -f
	@rm *.gcno -f
	@rm *.gcda -f
	@rm *.d -f
	@rm *.gcov -f

test_obj:
	$(CC) tests/t_main.c $(CFLAGS) $(LDFLAGS) -c
	$(CC) tests/t_options.c $(CFLAGS) $(LDFLAGS) -c

test:
	@make test_obj
	$(CC) $(TEST_OBJECT_FILES) $(CFLAGS) $(LDFLAGS) -o build/tests.out
	./build/tests.out
	@echo " "
	@make coverage
	@make cleanup

mem:
	@make memory

memory:
	@make obj
	$(CC) $(OBJECT_FILES) $(CFLAGS) -o build/build.out
#
#	Program starts here
#
	@echo ---------------
	valgrind ./build/build.out help
	@echo ---------------
	@make cleanup

coverage:
	@gcov $(TEST_OBJECT_FILES)
