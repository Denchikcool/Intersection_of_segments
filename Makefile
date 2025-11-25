CC := g++
CPPFLAGS := -std=c++17 -Wall -O2

OBJ = main.o Intersect.o

all: program

program: $(OBJ)
	$(CC) $(CPPFLAGS) -o program $(OBJ)

main.o: main.cpp Vector3D.h Segment3D.h Intersect.h
	$(CC) $(CPPFLAGS) -c main.cpp

Intersect.o: Intersect.cpp Vector3D.h Segment3D.h Intersect.h
	$(CC) $(CPPFLAGS) -c Intersect.cpp

clean:
	rm -f *.o program
