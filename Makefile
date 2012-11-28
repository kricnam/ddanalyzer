CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		analyzer.o HomeUI.o DataImportUI.o

LIBS =    -lboost_signals -lwt -lwthttp

TARGET =	analyzer

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
