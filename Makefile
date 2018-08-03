ninja-siblings.nes: ninja-siblings.o ninja-siblings.cfg
	ld65 -o $@ -C ninja-siblings.cfg ninja-siblings.o -m ninja-siblings.map.txt -Ln ninja-siblings.labels.ttx --dbgfile ninja-siblings.nes.dbg

ninja-siblings.chr: ninja-siblings.png
	png2chr $^

ninja-siblings.o: ninja-siblings.chr ninja-siblings.s background.inc
	ca65 ninja-siblings.s -g -o ninja-siblings.o

run: ninja-siblings.nes
	fceux $^

clean:
	rm -rf \
		ninja-siblings.o \
		ninja-siblings.nes \
		ninja-siblings.map.txt \
		ninja-siblings.labels.txt \
		ninja-siblings.nes.ram.nl \
		ninja-siblings.nes.0.nl \
		ninja-siblings.nes.1.nl \
		ninja-siblings.chr

.PHONY:
