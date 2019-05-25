#include "stdafx.h"

extern OctVoxel cube;
extern OctVoxel* label;

void findingCubeCenter(int &cubeNum) {

	//cube.cubeCenter.push_back(cube.startPoint);

	double dist1 = 0.0;
	double dist2 = 0.0;

	CVector3d nextRight, nextUp;
	CVector3d newMovePoint;

	CVector3d tempPoint;
	tempPoint.Set(cube.startPoint.x, cube.startPoint.y, cube.startPoint.z);

	CVector3d tempPointContact1, tempPointContact2;

	int count = 0;
	//21/05
	int tempUpCount(0);
	int tempRightCount(0);

	//22/05
	int  tempLableCount= 0;
	int uppp = 0;
	int righttt = 1;

	while (tempPoint != cube.goalPoint)
	{
		nextRight.Set(tempPoint.x + 1.0, tempPoint.y, tempPoint.z);
		double distanceRight = nextRight.PointLineDistance(cube.startPoint, cube.goalPoint);
		nextUp.Set(tempPoint.x, tempPoint.y + 1.0, tempPoint.z);
		double distanceUp = nextUp.PointLineDistance(cube.startPoint, cube.goalPoint);

		if (distanceRight > distanceUp) {
			//choose Up
			newMovePoint = nextUp;
			tempPoint = newMovePoint;
			
			cube.cubeCenter.push_back(newMovePoint);

			tempPointContact1.Set(nextUp.x - 0.5, nextUp.y - 0.5, nextUp.z - 0.5);
			tempPointContact2.Set(nextUp.x + 0.5, nextUp.y - 0.5, nextUp.z - 0.5);

			cube.edgeContactUpLeft.push_back(tempPointContact1);
			cube.edgeContactUpRight.push_back(tempPointContact2);

			tempPointContact1.Set(0.0, 0.0, 0.0);
			tempPointContact2.Set(0.0, 0.0, 0.0);

			cube.rotlabel.push_back(uppp);
			//tempLableCount++;
		}
		else {
			//choose Right
			newMovePoint = nextRight;
			tempPoint = newMovePoint;
			cube.cubeCenter.push_back(newMovePoint);

			tempPointContact1.Set(nextRight.x - 0.5, nextRight.y - 0.5, nextRight.z - 0.5);
			tempPointContact2.Set(nextRight.x - 0.5, nextRight.y + 0.5, nextRight.z - 0.5);

			cube.edgeContactRightLow.push_back(tempPointContact1);
			cube.edgeContactRightHigh.push_back(tempPointContact2);

			tempPointContact1.Set(0.0, 0.0, 0.0);
			tempPointContact2.Set(0.0, 0.0, 0.0);

			cube.rotlabel.push_back(righttt);

			//tempLableCount++;

		}

		//glMaterialfv(GL_FRONT, GL_SPECULAR, color);
		//DrawSphere(newMovePoint, 0.1);		
		//
		//cube.cubeCenter.push_back(newMovePoint);
		count++;
	}

	cubeNum = cube.cubeCenter.size();
	// cube.cubeCenter.push_back(cube.goalPoint);

	//cube.cubeCenter.erase(cube.cubeCenter.end() - 1); //do not include the goalPoint
	cube.rotRightCount.erase(cube.rotRightCount.end() - 1); //do not include rolling to the goalPoint


	cout << "size of Center" << cube.cubeCenter.size() << endl;

	for (int i = 0; i < cube.rotlabel.size(); i++) {
		//cout << "rotlabel " << cube.rotlabel[i] << endl;
	}
	//getchar();
}

void cubeRotation(CVector3d axisRotation) {
	double Theta = (90 * M_PI / 180);

	//move forward

	//rotation   	  
	CVector3d W_(0.0, 0.0, 0.0);
	//W_.Set(axisRotation.x, axisRotation.y, axisRotation.z);
	W_.Set(0.0, 1.0, 0.0);

	CVector3d tempOldPoint(0.0, 0.0, 0.0);
	tempOldPoint.Set(-0.5, cube.goalPoint.y, cube.goalPoint.z);

	//cout << "tempOldPoint" << tempOldPoint.x << " " << tempOldPoint.y << "  " << tempOldPoint.z << endl;

	CMatrix Rod1(3, 3);
	Rod1.SetZero();

	Rod1.At(0, 0) = cos(Theta) + W_.x*W_.x*(1 - cos(Theta));
	Rod1.At(1, 0) = W_.z*sin(Theta) + W_.x*W_.y*(1 - cos(Theta));
	Rod1.At(2, 0) = -W_.y*sin(Theta) + W_.x*W_.z*(1 - cos(Theta));

	Rod1.At(0, 1) = W_.x*W_.y*(1 - cos(Theta)) - W_.z*sin(Theta);
	Rod1.At(1, 1) = cos(Theta) + W_.y*W_.y*(1 - cos(Theta));
	Rod1.At(2, 1) = W_.x*sin(Theta) + W_.y*W_.z*(1 - cos(Theta));

	Rod1.At(0, 2) = W_.y*sin(Theta) + W_.x*W_.z*(1 - cos(Theta));
	Rod1.At(1, 2) = -W_.x*sin(Theta) + W_.y*W_.z*(1 - cos(Theta));
	Rod1.At(2, 2) = cos(Theta) + W_.z*W_.z*(1 - cos(Theta));

	//Rod1.At(0, 0) = cos(Theta) + W_.x*W_.x*(1 - cos(Theta));
	//Rod1.At(1, 0) = -W_.z*sin(Theta) + W_.x*W_.y*(1 - cos(Theta));
	//Rod1.At(2, 0) = W_.y*sin(Theta) + W_.x*W_.z*(1 - cos(Theta));
	//
	//Rod1.At(0, 1) = W_.x*W_.y*(1 - cos(Theta)) + W_.z*sin(Theta);
	//Rod1.At(1, 1) = cos(Theta) + W_.y*W_.y*(1 - cos(Theta));
	//Rod1.At(2, 1) = -W_.x*sin(Theta) + W_.y*W_.z*(1 - cos(Theta));
	//
	//Rod1.At(0, 2) = -W_.y*sin(Theta) + W_.x*W_.z*(1 - cos(Theta));
	//Rod1.At(1, 2) = W_.x*sin(Theta) + W_.y*W_.z*(1 - cos(Theta));
	//Rod1.At(2, 2) = cos(Theta) + W_.z*W_.z*(1 - cos(Theta));
	//--------------------------------------------------------------------

	cout << Rod1.At(0, 0) << "-" << Rod1.At(1, 0) << "-" << Rod1.At(2, 0) << endl;
	cout << Rod1.At(0, 1) << "-" << Rod1.At(1, 1) << "-" << Rod1.At(2, 1) << endl;
	cout << Rod1.At(0, 2) << "-" << Rod1.At(1, 2) << "-" << Rod1.At(2, 2) << endl;

	CVector3d temp_(0.0, 0.0, 0.0);
	temp_.x = Rod1.At(0, 0)*tempOldPoint.x + Rod1.At(0, 1)*tempOldPoint.y + Rod1.At(0, 2)*tempOldPoint.z;
	temp_.y = Rod1.At(1, 0)*tempOldPoint.x + Rod1.At(1, 1)*tempOldPoint.y + Rod1.At(1, 2)*tempOldPoint.z;
	temp_.z = Rod1.At(2, 0)*tempOldPoint.x + Rod1.At(2, 1)*tempOldPoint.y + Rod1.At(2, 2)*tempOldPoint.z;


	cout << "temp" << temp_.x << " " << temp_.y << "  " << temp_.z << endl;
	cube.newOrigin.Set(temp_.x + temp_.x + 0.5, temp_.y, temp_.z);
	cout << endl;

	//move backward


	for (int i = 0; i < cube.cubeCenter.size(); i++) {
		cout << "point[" << i << "] ";cube.cubeCenter[i].Print();
		//cube.rotlabel.push_back(i);

		//if (cube.rotRightFlag == true) {
		//	cout << "RightFlag[" << i << "] " << endl;
		//}
		//else {
		//	cout << "UpFlag[" << i << "] " << endl;
		//}
		cout << endl;
	}
	//cout << "cube.origin";	cube.origin.Print(); cout << endl;
	//cout << "cube.startPoint";	cube.startPoint.Print(); cout << endl;
	//cout << "cube.goalPoint";	cube.goalPoint.Print();	 cout << endl;
	//cout << "cube.newOrigin";	cube.newOrigin.Print();	 cout << endl;
	//cout << "cube.rotUpCount" << cube.rotUpCount.size() << endl;
	//cout << "cube.rotRightCount" << cube.rotRightCount.size() << endl;

	cout << endl;

	//getchar();
}