# occBasicSamples

Very basic OpenCASCADE examples that compile on Linux on the commandline with g++.
Only a .stl and .wrl is written that can be imported and viewed by a program like blender, MeshLab or view3dscene for example.
The purpose of these tiny example programs is to show the most basic usage of the Open CASCADE 3D library possible, thus flattening the learning curve for a beginner (like me).


## Installation

* OpenCascade (https://www.opencascade.com/doc/occt-7.1.0/overview/html/occt_dev_guides__building.html)
	* Building 3rd party libraries: see https://www.opencascade.com/doc/occt-7.1.0/overview/html/occt_dev_guides__building_3rdparty_linux.html
		* root> apt-get install g++ cmake cmake-curses-gui
		* root> apt-get install tcllib tklib tcl-dev tk-dev libfreetype-dev libxt-dev libxmu-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libfreeimage-dev libtbb-dev libgl2ps-dev 
		* root> apt-get install doxygen graphviz
		* root> apt-get install libqt4-dev libvtk6-dev libvtk6-qt-dev
	* Download OpenCascade from https://www.opencascade.com/content/latest-release. You must create an account in order to do so.
	* Configure (https://www.opencascade.com/doc/occt-7.1.0/overview/html/occt_dev_guides__building_cmake.html)
		* user> mkdir opencascade
		* user> cd opencascade/
		* user> cp ~/Downloads/opencascade-7.1.0.tgz .
		* user> tar -xvzf opencascade-7.1.0.tgz
		* user> mkdir install
		* user> mkdir build
		* user> cd build && cmake ../opencascade-7.1.0/
			* You have to adapt and configure your the variables as u need them. 
			* You will have to press the c key several times in order to solve all dependencies and generate the makefiles with the g-key then.
			* Here is what i have changed:
				INSTALL_DIR                      ../install                                                                                                                                                
				3RDPARTY_SKIP_DOT_EXECUTABLE     OFF
				INSTALL_DOC_Overview             ON                                                                                                                                                  
				INSTALL_FREETYPE                 ON  
				INSTALL_SAMPLES                  ON                                                                                                                                                        
				INSTALL_TCL                      ON                                                                                                                                                        
				INSTALL_TEST_CASES               ON                                                                                                                                                        
				INSTALL_TK                       ON                                                                                                                                                        
				USE_FREEIMAGE                    ON                                                                                                                                                        
				USE_GL2PS                        ON                                                                                                                                                        
				USE_TBB                          ON                                                                                                                                                        
				USE_VTK                          ON
	* Compile
		user> make
	* Install
		user> make install
		
	* TODO: ldconfig
	

*  These examples
    * TODO: 
        * add libraries
        * compile
        * link
        * run
        * view examples
        * makefile targets


## Available examples

Up to now there are examples for following basic shapes available:

**`Box:`**
![Box](docs/aBox.png)

**`Circle:`**
![Circle](docs/aCircle.png)

**`Cone:`**
![Cone](docs/aCone.png)

**`Cylinder:`**
![Cylinder](docs/aCylinder.png)

**`Sphere:`**
![Sphere](docs/aSphere.png)

**`Torus:`**
![Torus](docs/aTorus.png)

## References

* https://github.com/eryar/occQt
* https://www.opencascade.com
* https://www.opencascade.com/doc/occt-7.1.0/overview/html/index.html
* https://www.opencascade.com/doc/occt-7.1.0/overview/html/occt_dev_guides__building_3rdparty_linux.html
* https://www.blender.org
* http://www.meshlab.net
* https://castle-engine.sourceforge.io/view3dscene.php


## Authors:

* quirxi (https://github.com/quirxi)


## License

Distributed under the MIT License.


