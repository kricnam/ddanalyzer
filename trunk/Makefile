CXXFLAGS =	-O2 -ggdb -Wall -fmessage-length=0 -I/usr/local/include

OBJS =		analyzer.o HomeUI.o DataImportUI.o Session.o Worker.o USBFileContentView.o

LIBS = -L/usr/local/lib/   -lboost_signals -lwt -lwthttp -lwtdbo -lboost_system -lcrypt -lwtdbosqlite3

TARGET =	analyzer

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

test: USB*.cpp VTDR*.cpp test.cpp TraceLog.cpp
	g++ -o test -D_TRACE_LOG_ $^

clean:
	rm -f $(OBJS) $(TARGET)
