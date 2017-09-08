/* Compile and link:
*
*  g++ -c -pipe -O3 -std=c++11 -Wall -W -g -D_REENTRANT -I../include/opencascade -o main.o main.cpp
*  g++  -o aCone.exe main.o -L../lib   -lTKernel -lTKPrim -lTKTopAlgo -lTKSTL -lTKVRML -lTKSTEP -lTKBRep -lTKG3d -lTKMesh
*/
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <STEPControl_Writer.hxx>
#include <StlAPI_Writer.hxx>
#include <VrmlAPI_Writer.hxx>

int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
    // Cone
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(0.0, 10.0, 0.0));

    TopoDS_Shape aCone = BRepPrimAPI_MakeCone(anAxis, 3.0, 1.5, 5.0).Shape();
    BRepMesh_IncrementalMesh(aCone, 0.1, Standard_True);
    
    StlAPI_Writer aStlWriter;
    aStlWriter.Write(aCone, "aCone.stl");
    VrmlAPI_Writer aVrmlWriter;
    aVrmlWriter.Write(aCone, "aCone.wrl");
    STEPControl_Writer aStepWriter;
    aStepWriter.Transfer(aCone,STEPControl_AsIs);
    aStepWriter.Write("aCone.stp");
 
    return 0;
}
