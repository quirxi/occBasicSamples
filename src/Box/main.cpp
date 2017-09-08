/** 
* g++ -c -pipe -O3 -std=c++11 -Wall -W -g -D_REENTRANT -I../include/opencascade -o main.o main.cpp
* g++  -o aBox.exe main.o -L../lib   -lTKernel -lTKPrim -lTKTopAlgo -lTKSTL -lTKVRML -lTKSTEP -lTKBRep -lTKG3d -lTKMesh
*/
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <STEPControl_Writer.hxx>
#include <StlAPI_Writer.hxx>
#include <VrmlAPI_Writer.hxx>

int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
    // Box
    TopoDS_Shape aBox = BRepPrimAPI_MakeBox(3.0, 4.0, 5.0).Shape();
    BRepMesh_IncrementalMesh(aBox, 0.1, Standard_True);
    
    StlAPI_Writer aStlWriter;
    aStlWriter.Write(aBox, "aBox.stl");
    VrmlAPI_Writer aVrmlWriter;
    aVrmlWriter.Write(aBox, "aBox.wrl");
    STEPControl_Writer aStepWriter;
    aStepWriter.Transfer(aBox,STEPControl_AsIs);
    aStepWriter.Write("aBox.stp");
 
    return 0;
}
