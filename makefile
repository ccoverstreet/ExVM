driver: src/*.cpp src/*.h
	g++ src/*.cpp -o driver

run: driver
	./driver
