JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
Collection.java\
iterator.java\
Set.java\
SortedSet.java\
NavigableSet.java\
List.java\
Queue.java\
vector.java\
ArrayList.java\
TreeSet.java\
HashSet.java\
LinkedHashSet.java\
LinkedList.java\
PriorityQueue.java\
tester.java\
main_test.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class