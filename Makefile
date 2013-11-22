
test: test/test.c src/substr.c
	$(CC) -std=c99 $^ -o test/test
	./test/test

.PHONY: test
