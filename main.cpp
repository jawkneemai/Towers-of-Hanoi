
#include "Disk.h"
#include "Peg.h"
#include "gwindow.h"
#include <string>
#include "map.h"

// Function: promptForDisk()
// Purpose: Asks the user for the amount of disks to be used in the program.
// Input: None
// Output: an int with the number of disks desired
int promptForDisks()
{
    int answer = 0;
    bool temp = 0;
    while (!temp)
    {
        std::cout << "How many disks do you want to start with? (2-10)" << std::endl;
        std::cin >> answer;
    
        if (answer < 11 && answer > 1)
        {
            temp = 1;
        }
        else
        {
            std::cout << "That is not in the valid range." << std::endl;
            continue;
        }
    }
    return answer;
}

// Function: promptForPegs
// Purpose: Asks the user for what peg that want to start and end on.
// Input: two ints, one for the start peg and one for the end peg, which will have their values modified for the program
// Output: None
void promptForPegs(int& startPeg, int& endPeg)
{
    bool temp = 0;
    while (!temp)
    {
        std::cout << "What peg would you like to start on? (1, 2, or 3)" << std::endl;
        std::cin >> startPeg;
        if (startPeg < 4 && startPeg > 0)
        {
            std::cout << "What peg would you like to end on? (1, 2, or 3)" << std::endl;
            std::cin >> endPeg;
            if (endPeg != startPeg)
            {
                if (endPeg < 4 && endPeg > 0)
                {
                    temp = 1;
                }
                else
                {
                    std::cout << "That is not in the valid range. Please start over." << std::endl;
                    continue;
                }
                
            }
            else
            {
                std::cout << "The two values cannot be the same. Please start over." << std::endl;
                continue;
            }
        }
        else
        {
            std::cout << "That is not in the valid range." << std::endl;
            continue;
        }
    }
}

// Function: draw
// Purpose: Draws all of the pegs and disks.
// Input: GWindow to draw on, vector of Pegs
// Output: None
void draw(GWindow &gw, std::vector<Peg>& pegs)
{
    gw.clear();
    for (int i = 0; i < pegs.size(); i++)
    {
        pegs[i].draw(gw);
    }
}

// Function: moveDisk
// Purpose: Moves the "top" disk from the starting peg and puts it on the top of the destination peg.
// Input: GWindow by reference, the Pegs collection by reference, int for starting peg, and int for destination peg.
// Output: None
void moveDisk(GWindow& gw, std::vector<Peg>& pegs, int startPeg, int destinationPeg)
{
    pegs[destinationPeg].addDisk(pegs[startPeg].removeDisk());
    pause(500);
    draw(gw, pegs);
}

// Function: towerSolver
// Purpose: Solves the towers of Hanoi by moving all of the disks over from the start peg to the end peg.
// Input: GWindow to draw on, peg collection, integer of start peg, integer of end peg.
// Output: None
void towerSolver(GWindow& gw, std::vector<Peg>& pegs, int startPeg, int endPeg, int numberOfDisks)
{
    if (numberOfDisks < 1)
    {
        return;
    }
    else
    {
        //moveDisk(gw, pegs, startPeg, (3 - (startPeg + endPeg)));
        towerSolver(gw, pegs, startPeg, (3 - (startPeg + endPeg)), numberOfDisks-1);
        moveDisk(gw, pegs, startPeg, endPeg);
        towerSolver(gw, pegs, ( 3 - (startPeg + endPeg) ), endPeg, numberOfDisks-1);
    }
}

int main(int argc, char** argv)
{
    std::srand(std::time(0));
    
    // Making a map to pick a color randomly for the different disks
    Map<int, std::string>* Colors = new Map<int, std::string>;
    Colors->put(0,"Black");
    Colors->put(1,"Blue");
    Colors->put(2,"Cyan");
    Colors->put(3,"Dark Gray");
    Colors->put(4,"Gray");
    Colors->put(5,"Green");
    Colors->put(6,"Light Gray");
    Colors->put(7,"Magenta");
    Colors->put(8,"Orange");
    Colors->put(9,"Pink");
    Colors->put(10,"Red");
    Colors->put(11,"Yellow");
	
    // Variables
    
    double screenHeight = getScreenHeight();
    double screenWidth = getScreenWidth();
    GWindow gw(screenWidth/2, screenHeight/2);
    int startPeg = 0;
    int endPeg = 0;
    std::vector<Peg> pegs;
    double pegHeight = gw.getHeight() * 0.9;
    double pegWidth = gw.getWidth() / 50;
    
    // Creating Pegs
    
    Peg peg((gw.getWidth()/6), (pegHeight + (gw.getHeight()*0.05)), pegWidth, pegHeight);
    Peg peg1((gw.getWidth()/2), (pegHeight + (gw.getHeight()*0.05)), pegWidth, pegHeight);
    Peg peg2((5*(gw.getWidth()))/6, (pegHeight + (gw.getHeight()*0.05)), pegWidth, pegHeight);
    
    pegs.push_back(peg);
    pegs.push_back(peg1);
    pegs.push_back(peg2);
    
    // Prompt to begin program
    
    int numberOfDisks = promptForDisks();
    promptForPegs(startPeg, endPeg);
    
    startPeg = startPeg - 1;
    endPeg = endPeg - 1;
    int middlePeg = 3 - (startPeg + endPeg);
    
    // Add disks to corresponding peg
    
    double diskHeight = (pegHeight / (numberOfDisks + 1));
    
    for (int i = 0; i < numberOfDisks; i++)
    {
        int diskWidth = ( numberOfDisks - i ) * (((gw.getWidth()/3 - pegWidth))/(numberOfDisks)); // Basically disks will get smaller as i increases by a certain %
        Disk temp(pegs[startPeg].getX(), (pegs[startPeg].getY() - (diskHeight * i)), diskWidth, diskHeight, Colors); // More MATH
        pegs[startPeg].addDisk(temp);
    }
    
    draw(gw, pegs);
    
    
    // Solve the Towers of Hanoi
    
    towerSolver(gw, pegs, startPeg, endPeg, numberOfDisks);
    std::cout << "Completed!" << std::endl;

	return 0;
}
