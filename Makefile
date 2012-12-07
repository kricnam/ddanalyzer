CXXFLAGS =	-O2 -ggdb -Wall -fmessage-length=0 -I/usr/local/include

OBJS =		analyzer.o HomeUI.o DataImportUI.o Session.o Worker.o

LIBS = -L/usr/local/lib/   -lboost_signals -lwt -lwthttp -lwtdbo -lboost_system -lcrypt -lwtdbosqlite3

TARGET =	analyzer

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
