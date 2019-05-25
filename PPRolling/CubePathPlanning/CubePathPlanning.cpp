#include "stdafx.h"

using namespace std;

extern OctVoxel cube;
extern OctVoxel* label;
OctVoxel *cubeNew;
int cubeNum(0);
//function
void DrawCube(CVector3d centerPoint, int colorID);
void findingCubeCenter(int &cubeNum);
void cubeRotation(CVector3d axisRotation);

//openGL
void RunOpenGL(int argc, char *argv[]);

//main function
int CubePathPlanning(int argc, char* argv[]) {
	   
	//initialize the Start and Goal point on grid
	cube.startPoint.Set(0.5, 0.5, 0.5);
	cube.goalPoint.Set(5.5, 3.5, 0.5);
	

	
	findingCubeCenter(cubeNum);
	cout <<"cube.cubeCenter.size() "<< cube.cubeCenter.size();
	cout <<"cubeNum "<< cubeNum               << endl;

	//cube.rotAxis.Set(0.0, 1.0, 0.0);
	//cubeRotation(cube.rotAxis);
	//cout << "WTF" << endl;
	//getchar();

	//25/05
	
	cubeNew = new OctVoxel[cubeNum];

	cubeNew[0].getSelected();

	//RunOpenGL(argc, argv);

	return 0;
}


