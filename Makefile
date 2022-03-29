CXX = g++
CFLAGS = -g -Wall -std=c++11
NOMAIN = swatches.o
MAIN1OBJ = main1.o
MAIN2OBJ = main2.o
MAIN3OBJ = makinghtml.o
MAINOBJ = $(MAIN3OBJ)
TESTOBJ = test.o
OBJS = $(MAINOBJ) $(NOMAIN)
TESTOBJS = $(TESTOBJ) $(NOMAIN)
TEMPLATEFILES = dnode.h dlist.h dlist.template node_iterator.h node_iterator.template


a.out: $(OBJS) $(TEMPLATEFILES)
	$(CXX) $(CFLAGS) $(OBJS) -o $@

$(MAIN1OBJ): main1.cc $(TEMPLATEFILES)
	$(CXX) $(CFLAGS) -c main1.cc -o $@

$(MAIN2OBJ): main2.cc $(TEMPLATEFILES)
	$(CXX) $(CFLAGS) -c main2.cc -o $@

$(MAIN3OBJ): makinghtml.cc $(TEMPLATEFILES)
	$(CXX) $(CFLAGS) -c makinghtml.cc -o $@

swatches.o: swatches.cc swatches.h
	$(CXX) $(CFLAGS) -c swatches.cc -o $@


test: $(TESTOBJS) $(TEMPLATEFILES)
	$(CXX) $(CFLAGS) $(TESTOBJS) -o $@

$(TESTOBJ): $(patsubst %.o, %.cc, $@) $(TEMPLATEFILES)
	$(CXX) $(CFLAGS) -c $(patsubst %.o, %.cc, $@) -o $@


.PHONY: clean
clean:
	rm -rf $(NOMAIN) $(MAINOBJ) $(TESTOBJ) $(MAIN1OBJ) $(MAIN2OBJ) $(MAIN3OBJ) a.out