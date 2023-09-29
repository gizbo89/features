CC     = g++
HERE   = $(CURDIR)
INCLUDEPATH += -I/usr/local/include
CPPFLAGS = -Wall -std=c++11 -pthread -O3 $(INCLUDEPATH)
LIBRARIES= -L/usr/local/lib
LIBS     = -lsuperlu -lblas -llapack -lgfortran
DEPS   = nvector.h
EXEC   = exe 
OBJ    = $(HERE)/utils/tensor.o \
	 $(HERE)/utils/nvector.o \
	 $(HERE)/utils/nmatrix.o \
         $(HERE)/utils/dualdouble.o \
	 $(HERE)/searching_problems/puzzle8.o \
	 $(HERE)/searching_problems/problemtrip.o \
         $(HERE)/searching_problems/problempuzzle8.o \
         $(HERE)/searching_problems/searchalgorithms.o \
         $(HERE)/cryptosystems/cipher.o \
	 $(HERE)/cryptosystems/SPN.o \
         $(HERE)/cryptosystems/rsa.o \
	 input.o \
	 main.o
####$@: is the output variable, below is the .o
#Out of date if .o does not exist or .o is older than .c or DEPS=>build
%.o: %.cpp $(DEPS)  
	$(CC) $(CPPFLAGS) $(INCLUDEPATH) -c $< -o $@ 
##In the command below $^ represents all the contents in $(OBJ)
##make: has dependencies upon al $(OBJ)
make: $(OBJ)
	g++ $(LIBRARIES) -o $(EXEC) $^ $(LIBS)
clean:
	rm -f $(OBJ) exe
