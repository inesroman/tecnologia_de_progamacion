PROG:=main
SRCS:=programa.cc instruccion.cc main.cc
CXX:= g++ -O2

OBJS:=$(SRCS:.cc=.o)

all: $(PROG) main.s

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG)  core *.s *.o

programa.o: programa.h programa.cc
instruccion.o: instruccion.h instruccion.cc
main.o: main.cc programa.h instruccion.h
main.s: main.cc programa.h instruccion.h