program:
	gcc src/main.c -lm -o build.out
	@mv build.out ./build
	@echo ---------------
	./build/build.out
	@echo ---------------