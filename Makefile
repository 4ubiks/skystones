run:
	gcc -o skystones main.c skyprint.c -lncurses
	./skystones

clean:
	rm skystones

default:
	run