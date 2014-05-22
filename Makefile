LIBS = -lglfw3 -lGL -lGLU -lX11 -lXxf86vm -lpthread -lXrandr -lXi -lXcursor -lGLEW

all: inc/Drawable.h obj/Drawable.o obj/Exception.o game.cpp
	g++ -Wall obj/Drawable.o obj/Exception.o game.cpp $(LIBS) -o game

obj/Drawable.o: inc/Drawable.h inc/Exception.h src/Drawable.cpp
	g++ -c -Wall src/Drawable.cpp -o obj/Drawable.o
	
obj/Exception.o: inc/Exception.h src/Exception.cpp
	g++ -c -Wall src/Exception.cpp -o obj/Exception.o
