# Assumes ADMB_HOME has been set up correctly
EXEC = simple
SRCS = $(EXEC).cpp      \
       SexStructure.cpp \
       Stock.cpp

OBJS = $(SRCS:.cpp=.o)
TPLS = $(EXEC).tpl

CC = gcc
LD = g++

CC_OPT = -O3 -Wall -DSAFE_ALL
LDFLAGS = -O3 -g
LDLIBS  = $(ADMB_HOME)/lib/libadmb.a $(ADMB_HOME)/contrib/lib/libcontrib.a
CXXFLAGS = $(CC_OPT) -D__GNUDOS__ -Dlinux -DUSE_LAPLACE  -I. -I$(ADMB_HOME)/include -I$(ADMB_HOME)/contrib/include

all: $(EXEC)

# Link object file; build executable
$(EXEC): $(OBJS)
	$(LD) $(LDFLAGS) -o  $@ $(OBJS) $(LDLIBS)

# Use ADMB lexer to build the cpp file from the tpl
$(EXEC).cpp: $(TPLS)
	$(ADMB_HOME)/bin/tpl2cpp $(TPLS:.tpl=)

clean:
	$(RM) $(OBJS) $(EXEC).cpp \
  *.obj *.cov *.dep *.exe *.hes *.rpt *.log *.bar *.cor *.eva *.htp *.par *.std variance

# generate some information about what your are doing
rules:
	@echo EXEC = $(EXEC)
	@echo OBJS = $(OBJS)
	@echo SRCS = $(SRCS)
	@echo TPLS = $(TPLS)
	@echo OPT = $(OPT)
	@echo CC_OPT = $(CC_OPT)
	@echo PWD = $(PWD)
	@echo ADMB_HOME = $(ADMB_HOME)
	@echo CC = $(CC)
	$(CC) --version
	@echo LD = $(LD)
	@echo CXXFLAGS = $(CXXFLAGS)
	@echo LDFLAGS = $(LDFLAGS)
