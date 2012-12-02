CXXFLAGS =	-O2 -ggdb -Wall -fmessage-length=0

OBJS =		analyzer.o HomeUI.o DataImportUI.o Session.o User.o

LIBS =    -lboost_signals -lwt -lwthttp -lwtdbo -lboost_system -lcrypt -lwtdbosqlite3

TARGET =	analyzer

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
