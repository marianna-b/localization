CXX = $(shell fltk-config --cxx)
DEBUG = -g

CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) -I.
LDFLAGS = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK = $(CXX)

TARGET = main 
OBJS = main.o visualize.o trapezoid.o
SRCS = visualize.cpp trapezoid.cpp main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -f *.o 
	rm -f $(TARGET) 
