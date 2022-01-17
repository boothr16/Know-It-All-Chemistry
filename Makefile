OBJS = main.o

kia : $(OBJS)
	g++ -o kia $(OBJS)

main.o : FileParser.hpp HandlerType.hpp SpecType.hpp

.PHONY : clean

clean :
	-rm kia $(OBJS) 