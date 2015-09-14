CXX = clang++

SDL_LIB = -L/usr/include/SDL -lSDL2 -Wl,-rpath=/usr/lib
SDL_INCLUDE = -I/usr/include/SDL

CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = visualize

all: $(EXE)

$(EXE): visualize.o
	$(CXX) $< $(LDFLAGS) -o $@

visualize.o: visualize.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
