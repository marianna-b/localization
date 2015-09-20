CXX = $(shell fltk-config --cxx)
DEBUG = -g

CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) -I.
LDFLAGS = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK = $(CXX)

TARGET = visualize
OBJS = visualize.o
SRCS = visualize.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean: $(TARGET) $(OBJS)
	rm -f *.o 
	rm -f $(TARGET) 
