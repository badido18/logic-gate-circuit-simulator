CPP=g++ --std=c++11
CFLAGS= -Wall

all : exec

exec : main.o Gate.o InputGate.o OutputGate.o LogicGate.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp 
	$(CPP) $(CFLAGS) -c $<

Gate.o: Gate.cpp Gate.hpp 
	$(CPP) $(CFLAGS) -c $<
	
InputGate.o : InputGate.cpp InputGate.hpp
	$(CPP) $(CFLAGS) -c $<

OutputGate.o : OutputGate.cpp OutputGate.hpp
	$(CPP) $(CFLAGS) -c $<

LogicGate.o : LogicGate.cpp LogicGate.hpp
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o

test: all 
		./exec