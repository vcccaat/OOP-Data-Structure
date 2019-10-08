all: laughingGas.exe water.exe

laughingGas.exe: laughingGasMain.o nitrogen.o oxygen.o
	g++ -o laughingGas.exe laughingGasMain.o nitrogen.o oxygen.o

water.exe: waterMain.o hydrogen.o oxygen.o
	g++ -o water.exe waterMain.o hydrogen.o oxygen.o

waterMain.o: waterMain.cpp hydrogen.h oxygen.h
	g++ -c waterMain.cpp

laughingGasMain.o: laughingGasMain.cpp nitrogen.h oxygen.h
	g++ -c laughingGasMain.cpp

nitrogen.o:  nitrogen.cpp  nitrogen.h
	g++ -c  nitrogen.cpp 

oxygen.o: oxygen.cpp oxygen.h
	g++ -c oxygen.cpp 

hydrogen.o: hydrogen.cpp hydrogen.h
	g++ -c hydrogen.cpp
	
clean:
	rm -rf *.o
	rm -rf *.exe


