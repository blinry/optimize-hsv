default:
	mkdir -p bin
	clang src/optimize-hsv.cpp -lstdc++ -lm -I../optimizer/src -o bin/optimize-hsv
	./bin/optimize-hsv bin/lena.png
