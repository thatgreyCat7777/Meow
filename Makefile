CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++23 -g
LDFLAGS = 

SRC = hello.c strinput.c
OBJ = $(SRC:.c=.o)
EXEC = hello

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)