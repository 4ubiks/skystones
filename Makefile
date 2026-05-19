run:
	gcc -o skystones main.c skyprint.c skyinit.c -lncurses
	./skystones

clean:
	rm skystones

default:
	run