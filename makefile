HDIR = headers# directories/folders
CDIR = src
ODIR = objs
CPPFLAGS = -std=c++11 -g# flags
<<<<<<< HEAD
DEPS = $(wildcard $(HDIR)/*.h)
OBJ_FILES = main.o Customer.o EventTracker.o# put all dependencies for driver here
OBJS = $(patsubst %.o, $(ODIR)/%.o, $(OBJ_FILES))# replaces everything in source ending in arg1 with arg2
=======
DEPS = $(wildcard *.h)
# OBJ_FILES = main.o Customer.o EventTracker.o# put all dependencies for driver here
# OBJS = $(patsubst %.o, $(ODIR)/%.o, $(OBJ_FILES))# replaces everything in source ending in arg1 with arg2
OBJS = main.o Customer.o EventTracker.o
>>>>>>> 773a268f8425eb9f542c31ecaf67f4d36fb22dc4
vpath %.h headers# basically a search function
vpath %.cpp src
vpath %.o objs
DIRS = $(HDIR) $(CDIR) $(ODIR)
$(shell mkdir -p $(DIRS))# makes all directories if it's not there

<<<<<<< HEAD
$(ODIR)/%.o: %.cpp $(DEPS)
=======
%.o: %.cpp $(DEPS)
>>>>>>> 773a268f8425eb9f542c31ecaf67f4d36fb22dc4
	g++ $(CPPFLAGS) -c $< -o $@

main: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $^

clean:
<<<<<<< HEAD
	rm $(ODIR)/*.o main
=======
	rm *.o main
>>>>>>> 773a268f8425eb9f542c31ecaf67f4d36fb22dc4

.PHONY: clean all