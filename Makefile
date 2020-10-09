qtdriver:	Quadtree.cpp qttest.cpp Quadtree.h Node.h CityInfo.h
	g++ -std=c++11 -o qtdriver qttest.cpp Quadtree.cpp
clean:
	rm *.o qtdriver
