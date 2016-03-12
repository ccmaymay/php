CFLAGS = -O2 -std=gnu99

.PHONY: all
all: generate compute

generate compute: %: %.c
	gcc -o $@ $(CFLAGS) $< -lm

.PHONY: clean
clean:
	rm -f generate compute
