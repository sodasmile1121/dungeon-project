all: main

main: main.o Player.o Monster.o NPC.o Chest.o GameCharacter.o Object.o Item.o Poison.o Room.o Desert.o Forest.o Swamp.o Dungeon.o
	g++ -std=c++11 main.o Player.o Monster.o NPC.o Chest.o GameCharacter.o Object.o Item.o Poison.o Room.o Desert.o Forest.o Swamp.o Dungeon.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Player.o: Player.cpp
	g++ -std=c++11 -c Player.cpp

Monster.o: Monster.cpp
	g++ -std=c++11 -c Monster.cpp

NPC.o: NPC.cpp
	g++ -std=c++11 -c NPC.cpp

Chest.o: Chest.cpp
	g++ -std=c++11 -c Chest.cpp

GameCharacter.o: GameCharacter.cpp
	g++ -std=c++11 -c GameCharacter.cpp

Object.o: Object.cpp
	g++ -std=c++11 -c Object.cpp

Item.o: Item.cpp
	g++ -std=c++11 -c Item.cpp

Poison.o: Poison.cpp
	g++ -std=c++11 -c Poison.cpp

Room.o: Room.cpp
	g++ -std=c++11 -c Room.cpp

Desert.o: Desert.cpp
	g++ -std=c++11 -c Desert.cpp

Forest.o: Forest.cpp
	g++ -std=c++11 -c Forest.cpp

Swamp.o: Swamp.cpp
	g++ -std=c++11 -c Swamp.cpp

Dungeon.o: Dungeon.cpp
	g++ -std=c++11 -c Dungeon.cpp

.PHONY: clean

clean: 
	rm main main.o Player.o Monster.o NPC.o Chest.o GameCharacter.o Object.o Item.o Poison.o Room.o Desert.o Forest.o Swamp.o Dungeon.o
