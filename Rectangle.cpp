#include "Rectangle.h"

int Rectangle::rectanglesExisting;
int Rectangle::rectanglesCreated;


Rectangle::Rectangle()
{
    // Set the values of the variable elements of class Rectangle
    // Note that realistic values are not given, when using the
    // default constructor it is expected that the user will 
    // iniltialize the values of the members of the class using
    // the mutator functions after the default object has been 
    // created
    height = 1;
    width = 1;
    xLocation = 0;
    yLocation = 0;
    blockColour = Colour(0, 0, 0, 255);
    
    // Increment the counters for rectangles created and 
    // rectangles in existance: You are in the process of 
    // creating another Rectangle
    rectanglesCreated++;
    rectanglesExisting++;
}


Rectangle::~Rectangle()
{
    //Destructor
    //Each time a rectangle is destroyed decrement the
    //number of existing rectangles
    rectanglesExisting--;
}

void Rectangle::RectanglePrint()
{
    cout << setw(20) << "Width " << setw(9) << width << endl;
    cout << setw(20) << "Height " << setw(9) << height << endl;
    cout << setw(20) << "xLocation " << setw(9) << xLocation << endl; 
    cout << setw(20) << "yLocation " << setw(9) << yLocation << endl;
    cout << setw(20) << "rectanglesCreated " << setw(9) << rectanglesCreated << endl;
    cout << setw(20) << "rectanglesExisting " << setw(9) << rectanglesExisting << endl;
    cout << setw(20) << "blockColour" << setw(9) << blockColour << endl;
}


void Rectangle::RectangleDisplay(BMP& myImageValue, char theOutputFile[])
{
    int i;
    int j;
    int limit;
    
    if(yLocation < 0|| yLocation >= pageLength ||
        yLocation + height >= pageLength)
    {
        cerr << "point may be located outside of plotting page\n"
            << endl;
        return;
    }
    
    if(xLocation < 0|| xLocation >= pageWidth || 
        xLocation + width >= pageWidth )
    {
        cerr << "point may be located outside of plotting page\n"
            << endl;
        return;
    }
    
    // each pixel within the rectangle must be Set to the correct colour
    // myImageValue(i,j) is pixel j in row i
    // each value in the Colour object is Set for each pixel in 
    // the Rectangle
    for(j=yLocation; j<=(yLocation+height); j++)
    {
        for (i=xLocation; i<=(xLocation+width); i++)
        {
            myImageValue(i,j)->Red = blockColour.GetRedNumber();
            myImageValue(i,j)->Blue = blockColour.GetBlueNumber();
            myImageValue(i,j)->Green = blockColour.GetGreenNumber();
            myImageValue(i,j)->Alpha = blockColour.GetAlphaNumber();
        }
    }
    
    //write generated bitmap image to a file
    myImageValue.WriteToFile(theOutputFile);

}



