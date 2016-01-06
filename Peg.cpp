
#include "Peg.h"

Peg::Peg(int pegX, int pegY, int width, int height)
{
    mPegX = pegX;
    mPegY = pegY;
    mWidth = width;
    mHeight = height;
    mColor = "Black";
}

void Peg::draw(GWindow& gw)
{
    gw.setColor(mColor);
    int topLeftX = 0;
    int topLeftY = 0;
    
    topLeftX = mPegX - (mWidth / 2);
    topLeftY = mPegY - mHeight;
    
    gw.fillRect(topLeftX, topLeftY, mWidth, mHeight);

    for (int i = 0; i < mDisks.size(); i++)
    {
        mDisks[i].draw(gw);
    }
}

void Peg::addDisk(Disk newDisk)
{
    mDisks.push_back(newDisk);
    mDisks.back().setX(mPegX);
    mDisks.back().setY( mPegY + ((1-mDisks.size()) * mDisks[0].getHeight()));
}

Disk Peg::removeDisk()
{
    Disk tempDisk = mDisks.back();
    mDisks.pop_back();
    return tempDisk;
}

int Peg::getX()
{
    return mPegX;
}

int Peg::getY()
{
    return mPegY;
}

std::vector<Disk> Peg::getDisks()
{
    return mDisks;
}

int Peg::getDiskAmount()
{
    return mDisks.size();
}