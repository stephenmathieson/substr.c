
test: test/test.c src/substr.c deps/*/*.c
	$(CC) -std=c99 $^ -o test/test -Ideps -Isrc
	./test/test

.PHONY: test
