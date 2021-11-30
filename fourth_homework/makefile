task: main.cpp surface_sort.o shapes/parallelepiped.cpp shapes/shape.cpp shapes/sphere.cpp shapes/tetrahedron.cpp
	g++ -g -o task main.cpp surface_sort.o shapes/parallelepiped.cpp shapes/shape.cpp shapes/sphere.cpp shapes/tetrahedron.cpp -no-pie
surface_sort.o: surface_sort.asm
	nasm -f elf64 -g -F dwarf surface_sort.asm -l surface_sort.lst

