OBJS = main.o SpecType.o HandlerType.o FileParser.o

kia : $(OBJS)
	g++ -o kia $(OBJS)

main.o : FileParser.hpp HandlerType.hpp SpecType.hpp
SpecType.o : SpecType.hpp
HandlerType.o : SpecType.hpp HandlerType.hpp
FileParser.o : SpecType.hpp FileParser.hpp

.PHONY : clean

clean :
	-rm kia $(OBJS) 