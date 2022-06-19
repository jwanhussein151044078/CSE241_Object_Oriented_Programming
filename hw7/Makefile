JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
rectangle.java\
circle.java\
triangle.java\
composedshape.java\
polygonvect.java\
polygondyn.java\
polygon.java\
SHAPE.java\
function.java\
main_test.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class