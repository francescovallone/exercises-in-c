CC		=	gcc
CFLAGS		=	-Wall
PATH		=	C:\Users\Francesco\Documents\working\exercises-in-c\xx-12-2018\18-12-2018
OBJS	=	esercizio1.o sortinglib.o
OUTPUT	=	$(PATH)/out

$(OUTPUT):	$(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJS)

$(OBJS):	sortinglib.h
$(CC) -c $*.c