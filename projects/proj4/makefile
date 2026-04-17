CXX = g++
CXXFLAGS = -Wall -g

proj4: proj4.cpp Game.o Enemy.o Orc.o Tower.o ArcherTower.o MageTower.o Artillery.o
	$(CXX) $(CXXFLAGS) proj4.cpp Game.o Enemy.o Orc.o Tower.o ArcherTower.o MageTower.o Artillery.o -o proj4

Game.o: Game.cpp Game.h Tower.h ArcherTower.h MageTower.h Artillery.h Enemy.h Orc.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Enemy.o: Enemy.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

Orc.o: Orc.cpp Orc.h Enemy.h
	$(CXX) $(CXXFLAGS) -c Orc.cpp

Tower.o: Tower.cpp Tower.h Enemy.h
	$(CXX) $(CXXFLAGS) -c Tower.cpp

ArcherTower.o: ArcherTower.cpp ArcherTower.h Tower.h
	$(CXX) $(CXXFLAGS) -c ArcherTower.cpp

MageTower.o: MageTower.cpp MageTower.h Tower.h
	$(CXX) $(CXXFLAGS) -c MageTower.cpp

Artillery.o: Artillery.cpp Artillery.h Tower.h
	$(CXX) $(CXXFLAGS) -c Artillery.cpp
