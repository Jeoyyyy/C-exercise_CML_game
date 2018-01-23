OBJS = main.o room.o elevator.o helproom.o equipmentroom.o gamblingroom.o

adventure:$(OBJS)
	g++ -o $@ $(OBJS)

main.o:elevator.h room.h helproom.h position.h
room.o:room.h
elevator.o:elevator.h room.h position.h
helproom.o:helproom.h room.h position.h
equipmentroom.o:equipmentroom.h room.h
gamblingroom.o:gamblingroom.h room.h position.h
.PHONY:clean
clean:
	-rm adventure $(OBJS) *.exe