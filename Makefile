#Makefile for Cファイル

objs = kadai2.o kadai4.o kadai5.o monte.o  

hello: $(objs)
	gcc -Wall -O2 -o hello $(objs)

kadai2.o: kadai2.c
	gcc -c kadai2.c

kadai4.o: kadai4.c
	gcc -c kadai4.c

kadai5.o: kadai5.c
	gcc -c kadai5.c

monte.o: monte.c
	gcc -c monte.c

.PHOSY: clean

clean:
	rm -f hello $(objs)

