// ITP 365 Fall 2015
// HW3 - Towers of Hanoi
// Name: Johnathan Mai
// Email: johnathm@usc.edu
// Platform: Mac

#pragma once
#include <vector>
#include "Disk.h"
#include <string>


class Peg
{
    public:
    // Function: Peg()
    // Purpose: Constructor function. Sets up all of the member variables for the peg.
    // Input: pegX, pegY, width, height; all ints.
    // Output: None
    Peg(int pegX, int pegY, int width, int height);
    
    // Function: draw()
    // Purpose: Draws the peg based on the member variables of the class
    // Input: a GWindow by reference
    // Output: Peg drawn on the GWindow; nothing returned
    void draw(GWindow& gw);
    
    // Function: addDisk()
    // Purpose: Adds disk to the current peg shown on the screen
    // Input: A disk object to add to peg
    // Output: None
    void addDisk(Disk newDisk);
    
    // Function: removeDisk()
    // Purpose: Removes a disk from the current peg class
    // Input: None
    // Output: Disk object, the one being removed
    Disk removeDisk();
    
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
    
    // Function: getDisks()
    // Purpose: Returns the vector of disks on the peg
    // Input: none
    // Output: Vector of disks
    std::vector<Disk> getDisks();
    
    // Function: getDiskAmount
    // Purpose: Returns the amount of disks on the peg
    // Input: none
    // Output: Int of number of disks on peg
    int getDiskAmount();
    
    private:
    std::vector<Disk> mDisks;
    int mPegX;
    int mPegY;
    int mWidth;
    int mHeight;
    std::string mColor;
    
    
    
};