# ----------------------------------------------------------- 
# Makefile
#
# Options:
# 1. TMLIB = /home/kfarrell/os/ThreadMentor/Visual/libthreadclass.a
# 2. TMLIB = /home/kfarrell/os/ThreadMentor/NoVisual/libthreadclass.a
# ----------------------------------------------------------- 

CC        = c++
CFLAGS    = -g -O2 -Wno-deprecated -m32
DFLAGS    = -DPACKAGE=\"threadsystem\" -DVERSION=\"1.0\" -DPTHREAD=1 -DUNIX_MSG_Q=1 -DSTDC_HEADERS=1
IFLAGS    = -I/home/student/os/ThreadMentor/include
TMLIB     = /home/student/os/ThreadMentor/Visual/libthreadclass.a

OBJ_FILE  = Philosopher-4chairs.o Philosopher-4chairs-main.o
EXE_FILE  = Philosopher-4chairs

${EXE_FILE}: ${OBJ_FILE}
	${CC} ${CFLAGS}  -o ${EXE_FILE}  ${OBJ_FILE} ${TMLIB} -lpthread

Philosopher-4chairs.o : Philosopher-4chairs.cpp Philosopher-4chairs.h
	${CC} ${DFLAGS} ${IFLAGS} ${CFLAGS} -c Philosopher-4chairs.cpp

Philosopher-4chairs-main.o: Philosopher-4chairs-main.cpp Philosopher-4chairs.h
	${CC} ${DFLAGS} ${IFLAGS} ${CFLAGS} -c Philosopher-4chairs-main.cpp

clean:
	rm -f ${OBJ_FILE} ${EXE_FILE}

# End of Makefile
