CXX = g++
CFLAGS = -g -Wall -std=c++11
NOMAIN = 
MAINOBJ = main1.o
TESTOBJ = test.o
OBJS = $(MAINOBJ) $(NOMAIN)
TESTOBJS = $(TESTOBJ) $(NOMAIN)

a.out: $(OBJS) dnode.h dlist.h dlist.template node_iterator.h node_iterator.template
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(MAINOBJ): main1.cc dnode.h dlist.h dlist.template node_iterator.h node_iterator.template
	$(CXX) $(CFLAGS) -c main1.cc -o $@

swatches.o: swatches.cc swatches.h
	$(CXX) $(CFLAGS) -c swatches.cc -o $@


test: $(TESTOBJS) dnode.h dlist.h dlist.template node_iterator.h node_iterator.template
	$(CXX) $(CFLAGS) $(TESTOBJS) -o $@

$(TESTOBJ): test.cc dnode.h dlist.h dlist.template node_iterator.h node_iterator.template
	$(CXX) $(CFLAGS) -c test.cc -o $@


clean:
	rm -rf $(NOMAIN) $(MAINOBJ) $(TESTOBJ) a.out test