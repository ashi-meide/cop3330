polynomial: driver.o polynomial.o
	g++ driver.o polynomial.o -o polynomial

driver.o: driver.cpp polynomial.h
	g++ -c driver.cpp polynomial.h

polynomial.o: polynomial.cpp polynomial.h
	g++ -c polynomial.cpp polynomial.h
