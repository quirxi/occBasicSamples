SUBDIRS = Box Circle Cone Cylinder Sphere Torus

.PHONY: all clean proper depend world tags execute

all: 
	for DIR in $(SUBDIRS); do make -C $$DIR all; done

clean:
	for DIR in $(SUBDIRS); do make -C $$DIR clean; done

proper:
	for DIR in $(SUBDIRS); do make -C $$DIR proper; done

depend:
	for DIR in $(SUBDIRS); do make -C $$DIR depend; done

world:
	for DIR in $(SUBDIRS); do make -C $$DIR world; done

tags:
	for DIR in $(SUBDIRS); do make -C $$DIR tags; done
	
execute:
	for DIR in $(SUBDIRS); do cd $$DIR && ./a"$$DIR".exe && cd -; done
