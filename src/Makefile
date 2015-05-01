# Assumes ADMB_HOME has been set up correctly

ifeq ($(DEBUG),yes)
DESTDIR  = ../build/debug/
OBJDIR   = ../build/debug/objects/
BINDIR   = ../build/debug/bin/
LDFLAGS  = -O0
LDLIBS   = $(ADMB_HOME)/lib/libadmb.a $(ADMB_HOME)/lib/libadmb-contrib.a
CXXFLAGS = -g -D__GNUDOS__ -Dlinux -DUSE_LAPLACE  -I. -I$(ADMB_HOME)/include -I$(ADMB_HOME)/contrib/include
else
DESTDIR  = ../build/dist/
OBJDIR   = ../build/dist/objects/
BINDIR   = ../build/dist/bin/
LDFLAGS  = -O3
LDLIBS   = $(ADMB_HOME)/lib/libadmbo.a $(ADMB_HOME)/lib/libadmb-contribo.a
CXXFLAGS = -O3 -Wall -DSAFE_ALL -D__GNUDOS__ -Dlinux -DUSE_LAPLACE  -I. -I$(ADMB_HOME)/include -I$(ADMB_HOME)/contrib/include
endif

# Must come after the if statement so debug or dist dirs are correctly prepended
EXEC := simple
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TPLS := $(EXEC).tpl

CC = gcc
LD = g++
OBJECTS := $(addprefix $(OBJDIR), $(OBJS))

all: $(EXEC)
	@echo oocam build completed, DEBUG = $(DEBUG)

$(EXEC): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)
	@if [ ! -d "$(BINDIR)" ]; then mkdir -p $(BINDIR); fi
	mv $(EXEC).exe $(BINDIR)
	cp $(EXEC).dat $(BINDIR)

$(OBJDIR)%.o: %.cpp
	@if [ ! -d "$(DESTDIR)" ]; then mkdir -p $(DESTDIR); fi
	@if [ ! -d "$(OBJDIR)" ]; then mkdir -p $(OBJDIR); fi
	$(CXX) $(CXXFLAGS) -c $< -o $@

dist-clean:
	rm -rf ../build/dist/

debug-clean:
	rm -rf ../build/debug/

# Show variable values and compiler information
rules:
	@echo EXEC = $(EXEC)
	@echo DESTDIR = $(DESTDIR)
	@echo OBJDIR = $(OBJDIR)
	@echo OBJS = $(OBJS)
	@echo OBJECTS = $(OBJECTS)
	@echo SRCS = $(SRCS)
	@echo TPLS = $(TPLS)
	@echo ADMB_HOME = $(ADMB_HOME)
	@echo MAKE = $(MAKE)
	@echo DEBUG = $(DEBUG)
	@echo CC = $(CC)
	$(CC) --version
	@echo CXX = $(CXX)
	$(CXX) --version
	@echo LD = $(LD)
	@echo CXXFLAGS = $(CXXFLAGS)
	@echo LDFLAGS = $(LDFLAGS)
