
#pragma once
#include <string>
#include "gwindow.h"
#include "map.h"
#include <cstdlib>

class Disk
{
    public:
    // Function: Disk Constructor
    // Purpose: Does nothing
    // Input: None
    // Output: None
    Disk();
    
    // Function: Disk Parametrized Constructor
    // Purpose: Constructs a disk class with the given parameters
    // Input: X and Y coordinates as ints, and the width and height as ints, map of colors to randomize colors of the disks
    // Output: None
    Disk(int diskX, int diskY, int width, int height, Map<int,std::string>* Colors);
    
    // Function: setX
    // Purpose: Sets the x coordinate of the bottom center of the disk
    // Input: X coordinate as int
    // Output: None
    void setX(int diskX);
    
    // Function: setY
    // Purpose: Sets the y coordinate of the bottom center of the disk
    // Input: Y coordinate as int
    // Output: None
    void setY(int diskY);
    
    // Function: getX
    // Purpose: Returns the x coordinate as an int
    // Input: none
    // Output: X coordinate as an int
    int getX();
    
    // Function: getY
    // Purpose: Returns the y coordinate as an int
    // Input: none
    // Output: Y coordinate as an int
    int getY();
    
    // Function: getHeight
    // Purpose: Returns the height as an int
    // Input: none
    // Output: Height as an int
    int getHeight();
    
    // Function: draw()
    // Purpose: Draws a disk based on the member variables of the disk.
    // Input: A GWindow by reference
    // Output: None
    void draw(GWindow& gw);
    
    private:
    int mDiskX;
    int mDiskY;
    int mHeight;
    int mWidth;
    std::string mColor;
    
    
};