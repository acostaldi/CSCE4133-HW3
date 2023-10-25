PROJECT_DIR=.

# Please edit this line to GRADUATE=1 if you are graduate students.
GRADUATE=0

ifeq ($(OS),Windows_NT)
	# You are using Windows
	MINGW_BIN=C:/Homework/mingw64/bin
	OPENCV_DIR=C:/homework/opencv/build/install
	CC=${MINGW_BIN}/gcc.exe
	CXX=${MINGW_BIN}/g++.exe
	PROGRAM=main.exe
else
	# You are using Linux or MacOS
	CC=gcc
	CXX=g++
	PROGRAM=main
endif

CFLAGS=-I${PROJECT_DIR}/include/ -std=c++11
FILES=linked_list.cpp graph.cpp queue.cpp stack.cpp bfs.cpp bst.cpp main.cpp

# Using OpenCV for Visualization
OPENCV=1
OPENCV4=0
ifeq ($(OS),Windows_NT)
	ifeq ($(OPENCV), 1)
		CFLAGS+= -DOPENCV=1 -I${OPENCV_DIR}/include -std=c++11
		LDFLAGS+= -L${OPENCV_DIR}/x64/mingw/bin -lopencv_imgcodecs3413 -lopencv_core3413 -lopencv_highgui3413 -lopencv_imgproc3413
	endif
else
	ifeq ($(OPENCV), 1)
		ifeq ($(OPENCV4), 0)
			LDFLAGS+=  `pkg-config --libs opencv`
			CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv`
		else
			LDFLAGS+= `pkg-config --libs opencv4`
			CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv4`
		endif
	endif
endif


ifeq (${GRADUATE}, 1)
	CFLAGS += -DGRADUATE=1
	FILES += avl.cpp
endif

SRC_DIR=${PROJECT_DIR}/src/

SRC_FILES=$(addprefix ${SRC_DIR}, ${FILES})

all: bfs

bfs: main
	./bin/${PROGRAM}

main: ${SRC_FILES}
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/${PROGRAM} 


