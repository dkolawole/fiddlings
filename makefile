linked_list: linked_list.o
	g++ -o linked_list linked_list.o

linked_list.o: linked_list.h linked_list.cc
	g++ -c -g linked_list.cc

clean:
	rm -v *.o