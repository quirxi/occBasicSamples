/* Compile and link:
*
*  g++ -c -pipe -O3 -std=c++11 -Wall -W -g -D_REENTRANT -I../include/opencascade -o main.o main.cpp
*  g++  -o aSphere.exe main.o -L../lib   -lTKernel -lTKPrim -lTKTopAlgo -lTKSTL -lTKVRML -lTKSTEP -lTKBRep -lTKG3d -lTKMesh
*/
#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <STEPControl_Writer.hxx>
#include <StlAPI_Writer.hxx>
#include <VrmlAPI_Writer.hxx>

int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
    // Sphere
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(0.0, 20.0, 0.0));

    TopoDS_Shape aSphere = BRepPrimAPI_MakeSphere(anAxis, 3.0).Shape();
    BRepMesh_IncrementalMesh(aSphere, 0.1, Standard_True);
    
    StlAPI_Writer aStlWriter;
    aStlWriter.Write(aSphere, "aSphere.stl");
    VrmlAPI_Writer aVrmlWriter;
    aVrmlWriter.Write(aSphere, "aSphere.wrl");
    STEPControl_Writer aStepWriter;
    aStepWriter.Transfer(aSphere,STEPControl_AsIs);
    aStepWriter.Write("aSphere.stp");
 
    return 0;
}
