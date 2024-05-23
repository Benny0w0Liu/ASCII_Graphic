CC = g++
Target = main
Target_1 = Canva
Target_2 = Matrix
build:
	$(CC) -c $(Target).cpp $(Target_1).cpp $(Target_2).cpp;
	$(CC) -o $(Target) $(Target).o $(Target_1).o $(Target_2).o;
