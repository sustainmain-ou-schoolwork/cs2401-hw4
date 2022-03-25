CXX = g++
CFLAGS = -g -Wall -std=c++11
NOMAIN = dlist.o makinghtml.o swatches.o
MAINOBJ = main1.o
TESTOBJ = test.o
OBJS = $(MAINOBJ) $(NOMAIN)
TESTOBJS = $(TESTOBJ) $(NOMAIN)

a.out: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(MAINOBJ): main1.cc dlist.h
	$(CXX) $(CFLAGS) -c main1.cc -o $@

dlist.o: dlist.cc dlist.h
	$(CXX) $(CFLAGS) -c dlist.cc -o $@

makinghtml.o: makinghtml.cc swatches.h
	$(CXX) $(CFLAGS) -c makinghtml.cc -o $@

swatches.o: swatches.cc swatches.h
	$(CXX) $(CFLAGS) -c swatches.cc -o $@


test: $(TESTOBJS)
	$(CXX) $(CFLAGS) $(TESTOBJS) -o $@

$(TESTOBJ): test.cc
	$(CXX) $(CFLAGS) -c test.cc -o $@


clean:
	rm -rf $(NOMAIN) $(MAINOBJ) $(TESTOBJ) a.out test