all:TPT
TPT:main.o Component.o Panel.o Layer.o Particle.o
	g++ -O2 main.o -lsfml-graphics -lsfml-window -lsfml-system -I ../includes Panel.o Particle.o Layer.o Component.o -o TPT
main.o: main.cpp
	g++ -c main.cpp -o main.o -I../includes
Component.o: ui/Component.cpp ../includes/ui/Component.hpp
	g++ -I../includes -c ui/Component.cpp -o Component.o
Panel.o:ui/Panel.cpp ../includes/ui/Panel.hpp
	g++ -I../includes -c ui/Panel.cpp -o Panel.o
Layer.o:Layer.cpp Layer.hpp
	g++ -c Layer.cpp -o Layer.o
Particle.o:Particles/Particle.cpp Particles/Particle.hpp
	g++ -c Particles/Particle.cpp -o Particle.o