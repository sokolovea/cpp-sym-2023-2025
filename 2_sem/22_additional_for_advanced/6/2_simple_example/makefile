all: client server
client: client.o
	g++ -o client client.o
server: server.o
	g++ -o server server.o
client.o: client.cpp
	g++ -Wall -Wextra -c -o client.o client.cpp
server.o: server.cpp
	g++ -Wall -Wextra -c -o server.o server.cpp
clean:
	rm -f client server *.o
