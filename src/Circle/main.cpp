/* Compile and link:
*
*  g++ -c -pipe -O3 -std=c++11 -Wall -W -g -D_REENTRANT -I../include/opencascade -o main.o main.cpp
*  g++  -o aCircle.exe main.o -L../lib -lTKernel -lTKPrim -lTKTopAlgo -lTKSTL -lTKVRML -lTKSTEP -lTKBRep -lTKG3d -lTKMesh
*/
#include <gp_Circ.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <STEPControl_Writer.hxx>
//#include <StlAPI_Writer.hxx>
#include <VrmlAPI_Writer.hxx>

int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
    // Circle
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(16.0, 60.0, 0.0));
    TopoDS_Edge aCircle = BRepBuilderAPI_MakeEdge(gp_Circ(anAxis, 3.0));
    
    BRepMesh_IncrementalMesh(aCircle, 0.1, Standard_True, 0.1);
    
//    StlAPI_Writer aStlWriter;
//    aStlWriter.Write(aCircle, "aCircle.stl");
    VrmlAPI_Writer aVrmlWriter;
    aVrmlWriter.Write(aCircle, "aCircle.wrl");
    STEPControl_Writer aStepWriter;
    aStepWriter.Transfer(aCircle,STEPControl_AsIs);
    aStepWriter.Write("aCircle.stp");
 
    return 0;
}
