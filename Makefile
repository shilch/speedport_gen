all:
	gcc speedport_gen.c -o speedport_gen

clean:
	rm -r speedport_gen || true