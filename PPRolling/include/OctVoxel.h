#pragma once

#ifndef _OCTREE_H_
#define _OCTREE_H_


#include "stdafx.h"
#include "Color3D.h"


class OctVoxel {
public:
	//for animation
	int countt;
	float count_x, count_y;
	double angle;
	CVector3d rotAxis;
	CVector3d newOrigin;

	int lableNum;
	vector<int> rotlabel;
	
	vector<int> rotUpCount;
	vector<int> rotRightCount;

	bool rotRightFlag;
	bool rotUpFlag;

	void SetRotationRight(bool);
	void SetRotationUp(bool);

	bool SetRotationRight(void);
	bool SetRotationUp(void);
	
	//edges contact for cube
	vector<CVector3d> edgeContactRightLow;
	vector<CVector3d> edgeContactRightHigh;
	vector<CVector3d> edgeContactUpLeft;
	vector<CVector3d> edgeContactUpRight;

	//for voxel
	OctVoxel();
	CVector3d origin;
	double length;
	double height;

	void SetOrigin(CVector3d ori);
	void SetVertexWorld(CVector3d* vertW);

	vector<CVector3d> cubeCenter;
	vector<CVector3d> cubeOrigin;
	CVector3d startPoint, goalPoint;
	   
	//
	//25/06

	double coordX;
	double coordY;
	double coordZ;
	double directionX;
	double directionY;
	double directionZ;
	//CVector3d coord;
	//CVector3d direction;
	bool selected;
	OctVoxel(double cX, double cY, double cZ,
		     double dX, double dY, double dZ) {
		coordX = cX;
		coordY = cY;
		coordZ = cZ;

		directionX = dX;
		directionY = dY;
		directionZ = dZ;

		selected = false;
	}

	double getCoordX()
	{
		return coordX;
	}
	double getCoordY()
	{
		return coordY;
	}
	double getCoordZ()
	{
		return coordZ;
	}
	double getDirectionX()
	{
		return directionX;
	}
	double getDirectionY()
	{
		return directionY;
	}
	double getDirectionZ()
	{
		return directionZ;
	}
	bool getSelected()
	{
		return selected;
	}
	void setSelected(bool what)
	{
		selected = what;
	}
};

class Model {

public:
	vector<CVector3d> cubeCenter;


	Model();
	~Model();
};





#endif 