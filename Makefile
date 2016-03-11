CFLAGS = -O2 -std=gnu99

.PHONY: all
all: generate compute

generate: generate.c
	gcc -o $@ $(CFLAGS) $< -lgsl -lcblas

compute: compute.c
	gcc -o $@ $(CFLAGS) $< -lm

.PHONY: clean
clean:
	rm -f generate compute
