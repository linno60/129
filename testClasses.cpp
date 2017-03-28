#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "EasyBMP.h"
#include "Colour.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Gasket.h"
#include "DisplayBackground.h"
using namespace std;


// main program to test class Rectangle
// Creates and prints a rectangle
int main()
{
	//Please note that this is the correct location for BMP myImage
	//The program will work if you make this declaration global (as indicated in lab writeup)
	//However global variables should not be used as arguments of functions
	BMP myImage;
	Colour C1(0, 0, 255, 255);     //blue rectangle R2
	Colour C2(0, 0, 0, 255);	   //large black rectangle R3
	Colour CB(0, 255, 0, 255);     //green background
	Colour C3(255,0,0,255);		   //red rectangle R4
	Colour C4(128,128,128,128);	   //small grey rectangle R1
	char numbers[10] = {'\0'};
	char myFileName[128] = {'\0'};

	Rectangle R1; 
	Rectangle R2( 80, 300, C2);
	Rectangle R3( 10, 150, 500, 400, C3 );
	Rectangle R4( 200, 200, 100, 250, C4);

	int it, sid, xx, yy;

	R1.SetWidth(30);
	R1.SetHeight(50);
	R1.SetXLocation(100);
	R1.SetYLocation(220);
	R1.SetColour(C1);

	R2.SetHeight(400);
	R2.SetWidth(500);


	// print the values of the rectagles
	cout << endl;
	cout << "Getting Width " << R1.GetWidth() << endl;
	cout << "Getting Height " << R1.GetHeight() << endl;
	cout << "Getting xLocation " << R1.GetXLocation() << endl; 
	cout << "Getting yLocation " << R1.GetYLocation() << endl;
	cout << "Getting rectanglesCreated " << R1.GetRectanglesCreated()<< endl;
	cout << "Getting rectanglesExisting " << R1.GetRectanglesExisting() << endl;
	cout << "Getting blockColour" << R1.GetBlockColour() << endl;
	cout << endl;

	cout.setf(ios::left);
	R2.RectanglePrint();
	cout << endl << endl;
	R3.RectanglePrint();
	cout << endl;
	R4.RectanglePrint();
	cout << endl;

	// Test relations between rectangles
	if(R1.DoesOverlay(R2))
	{
		cout << "R1 overlays R2" << endl;
	}
	if(R1.DoesOverlay(R3))
	{
		cout << "R1 overlays R3" << endl;
	}
	if(R1.DoesOverlay(R4))
	{
		cout << "R1 overlays R4" << endl;
	}
	if(R2.DoesOverlay(R1))
	{
		cout << "R2 overlays R1" << endl;
	}
	if(R2.DoesOverlay(R3))
	{
		cout << "R2 overlays R3" << endl;
	}
	if(R2.DoesOverlay(R4))
	{
		cout << "R2 overlays R4" << endl;
	}
	if(R3.DoesOverlay(R1))
	{
		cout << "R3 overlays R1" << endl;
	}
	if(R3.DoesOverlay(R2))
	{
		cout << "R3 overlays R2" << endl;
	}
	if(R3.DoesOverlay(R4))
	{
		cout << "R3 overlays R4" << endl;
	}
	if(R4.DoesOverlay(R1))
	{
		cout << "R4 overlays R1" << endl;
	}
	if(R4.DoesOverlay(R2))
	{
		cout << "R4 overlays R2" << endl;
	}
	if(R4.DoesOverlay(R3))
	{
		cout << "R4 overlays R3" << endl;
	}
	if(R1.DoesIntersect(R2))
	{
		cout << "R1 intersects R2" << endl;
	}
	if(R1.DoesIntersect(R3))
	{
		cout << "R1 intersects R3" << endl;
	}
	if(R1.DoesIntersect(R4))
	{
		cout << "R1 intersects R4" << endl;
	}
	if(R2.DoesIntersect(R1))
	{
		cout << "R2 intersects R1" << endl;
	}
	if(R2.DoesIntersect(R3))
	{
		cout << "R2 intersects R3" << endl;
	}
	if(R2.DoesIntersect(R4))
	{
		cout << "R2 intersects R4" << endl;
	}
	if(R3.DoesIntersect(R1))
	{
		cout << "R3 intersects R1" << endl;
	}
	if(R3.DoesIntersect(R2))
	{
		cout << "R3 intersects R2" << endl;
	}
	if(R3.DoesIntersect(R4))
	{
		cout << "R3 intersects R4" << endl;
	}
	if(R4.DoesIntersect(R2))
	{
		cout << "R4 intersects R1" << endl;
	}
	if(R4.DoesIntersect(R3))
	{
		cout << "R4 intersects R2" << endl;
	}
	if(R4.DoesIntersect(R4))
	{
		cout << "R4 intersects R3" << endl;
	}


	//Create the bitmap
	//Load the background bitmap
	//Plot each rectangle to the bitmap
	//Note the last rectangle plotted will appear on
	//to of previous rectangles
	//NOTE: background colour should be CB (typo in lab writeup sait C1)
	InitBackground(myImage, CB, 600, 800);
	R3.RectangleDisplay(myImage, "rectangleTest.bmp");
	R2.RectangleDisplay(myImage, "rectangleTest.bmp");
	R4.RectangleDisplay(myImage, "rectangleTest.bmp");
	R1.RectangleDisplay(myImage, "rectangleTest.bmp");

	cout << endl << endl;

	//Test the = operator
	//make R4 a copy of the R3 rectangle
	R4 = R3;

	//Test the << operator
	//Print R3 and R4 using the overloaded << operator
	//This will also show that R4 is the same as R3
	cout << "R3" << endl << R3;
	cout << "R4" << endl << R4;
	cout << endl << endl;

	//Test the == operator
	cout << "Testing = and == answer should be true (1) " << (R3==R4);
	cout << endl;
	cout << "Testing = and == answer should be false (0) " << (R3==R1);
	cout << endl;


	// Triangle test here
	Triangle T1 ( 100, 200, C2); 
	T1.SetSideLength(100);
	T1.TrianglePrint();
	cout << endl;
	ResetBackground(myImage, CB, 600, 800);
	T1.TriangleDisplay(myImage, "triangleTest.bmp");

	//Gasket test here

	cout << " iterations: ";
	cin >> it;
	cout << " sideLen: ";
	cin >> sid;
	cout <<"xloc: ";
	cin >> xx;
	cout << "yloc: ";
	cin >> yy;

	ResetBackground(myImage, CB, 600, 800);


	Gasket G1(it, xx, yy, sid, C2);
	ResetBackground(myImage, C3, 600, 800);
	G1.GasketDisplay(myImage, k, "gasketTest.bmp");
	return 0;
}

