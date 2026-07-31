run:
	gcc -o skystones main.c skyprint.c skyinit.c skyfuncs.c pieceInfo.c -lncurses
	./skystones

clean:
	rm skystones

debug:
	gcc -o skystones main.c skyprint.c skyinit.c skyfuncs.c pieceInfo.c -lncurses
	lldb-server gdbserver :1234 ./skystones

default:
	run