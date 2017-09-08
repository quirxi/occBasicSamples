/* Compile and link:
*
*  g++ -c -pipe -O3 -std=c++11 -Wall -W -g -D_REENTRANT -I../include/opencascade -o main.o main.cpp
*  g++  -o aTorus.exe main.o -L../lib   -lTKernel -lTKPrim -lTKTopAlgo -lTKSTL -lTKVRML -lTKSTEP -lTKBRep -lTKG3d -lTKMesh
*/
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <STEPControl_Writer.hxx>
#include <StlAPI_Writer.hxx>
#include <VrmlAPI_Writer.hxx>

int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
    // Torus
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(0.0, 40.0, 0.0));

    TopoDS_Shape aTorus = BRepPrimAPI_MakeTorus(anAxis, 3.0, 1.0).Shape();
    BRepMesh_IncrementalMesh(aTorus, 0.1, Standard_True);
    
    StlAPI_Writer aStlWriter;
    aStlWriter.Write(aTorus, "aTorus.stl");
    VrmlAPI_Writer aVrmlWriter;
    aVrmlWriter.Write(aTorus, "aTorus.wrl");
    STEPControl_Writer aStepWriter;
    aStepWriter.Transfer(aTorus,STEPControl_AsIs);
    aStepWriter.Write("aTorus.stp");
 
    return 0;
}
