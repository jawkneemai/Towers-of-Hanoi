// ITP 365 Fall 2015
// HW3 - Towers of Hanoi
// Name: Johnathan Mai
// Email: johnathm@usc.edu
// Platform: Mac

#include "Disk.h"

Disk::Disk()
{
    
}

Disk::Disk(int diskX, int diskY, int width, int height, Map<int, std::string>* Colors)
{
    setX(diskX);
    setY(diskY);
    mHeight = height;
    mWidth = width;
    
    // Randomly generate a color from the map
    int index = std::rand()%(Colors->size());
    mColor = Colors->get(index);
}

void Disk::setX(int diskX)
{
    mDiskX = diskX;
}

void Disk::setY(int diskY)
{
    mDiskY = diskY;
}

int Disk::getX()
{
    return mDiskX;
}

int Disk::getY()
{
    return mDiskY;
}

int Disk::getHeight()
{
    return mHeight;
}

void Disk::draw(GWindow& gw)
{
    gw.setColor(mColor);
    int topLeftX = 0;
    int topLeftY = 0;
    
    topLeftX = mDiskX - (mWidth / 2);
    topLeftY = mDiskY - mHeight;
    
    gw.fillRect(topLeftX, topLeftY, mWidth, mHeight);    
}

