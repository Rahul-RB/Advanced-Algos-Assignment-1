all: a.out 
a.out: run.o dynamicTable.o 
	gcc run.o dynamicTable.o -lm	

run.o: run.c headers.h opsArray.h
	gcc -c run.c 

dynamicTable.o: dynamicTable.c headers.h
	gcc -c dynamicTable.c 

clean:
	rm -rf *.o