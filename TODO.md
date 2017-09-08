TODOS

* Cut
* Combine
* Fuse
* *.png output etc. 
* Find out in which library missing symbols are in order to add them to the Makefile:
    * ~/PROJECTS/OpenCascade/install/lib$ for FILE in *.so; do echo $FILE; nm -gC $FILE | fgrep STEPControl_Writer  ; done
