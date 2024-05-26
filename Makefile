CC=g++
CXXFLAGS=-std=c++17 -Wall -Wextra
TARGET=Application
PRO=Application.pro
OBJS_DIR=objs/
MOC_DIR=moc/
QBLOAT=.qmake.stash qMakefile ui_mainwindow.h qrc_resources.cpp
ZIP_NAME=xsnieh00-xlogin00.zip
ZIP_TARGETS=src/ 
#Makefile README.txt doc/ examples/ $(PRO)

.PHONY: all clean build zip run

all: clean build

build:
	qmake ${PRO} -o qMakefile
	make -f qMakefile

run: all
	./${TARGET}

doxygen:
	doxygen doc/Doxyfile

zip:
	rm -f ${ZIP_NAME}
	zip -r ${ZIP_NAME} ${ZIP_TARGETS}

clean:
	rm -rf ${OBJS_DIR}
	rm -rf ${MOC_DIR}
	rm -f ${TARGET}
	rm -f ${ZIP_NAME}
	rm -f ${QBLOAT}