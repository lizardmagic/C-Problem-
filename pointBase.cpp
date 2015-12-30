///////////////////////////////////////////////////////////////////////////////////
// Filename:		pointBase.cpp												//
// Author:			Elizabeth King												//
// Date Modified:	10/04/2015 													//
//																				//
///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "NodePoint.cpp"

using namespace std;

const int maxSize = 5000;
char grid[maxSize];
int width_g;
int height_g;

class PointBase
{
public:

	int x, y;
	
	/*****************************************************************
	* Description:		PointBase Constructor
	*  
	* Returns:			NIL
	*
	* Parameters:		int xPoistion, int yPosition
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

	PointBase(int xPosition, int yPosition)
	{
		x = xPosition;
		y = yPosition;
	}

	bool operator == (const PointBase& other)
	{

		return ( x == other.x && y == other.y );

	}

};


private:

};

	/*****************************************************************
	* Description:		getPossiblePositions 
	* Use of Push back() Adds a new element at the end of the vector, 
	* after its current last element. The content of val is copied 
	* to the new element. This increases the container size by one, 
	* which causes an automatic reallocation of the allocated storage space.
	*					
	* 
	* Returns:			
	*
	* Parameters:		Point location, std::vector<Point> &positions
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	
	******************************************************************/

class Point : public PointBase
{
public:

	Point(int x, int y) : PointBase(x, y) {};

	Point(const NodePoint& other) : PointBase(other.x, other.y) {};



};
	/*****************************************************************
	* Description:		getPossiblePositions 
	* Use of Push back() Adds a new element at the end of the vector, 
	* after its current last element. The content of val is copied 
	* to the new element. This increases the container size by one, 
	* which causes an automatic reallocation of the allocated storage space.
	*					
	* 
	* Returns:			
	*
	* Parameters:		Point location, std::vector<Point> &positions
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	
	******************************************************************/


void getPossiblePositions(Point location, std::vector<Point> &positions)
{
	//---------north------------//

	Point north(location.x, location.y - 1);

	Point northEast(location.x - 1, location.y - 1);

	Point northWest(location.x + 1, location.y - 1);


	//---------east------------//

	Point east(location.x - 1, location.y);


	//---------west------------//

	Point west(location.x + 1, location.y);


	//---------south------------//

	Point south(location.x, location.y + 1);

	Point southEast(location.x - 1, location.y + 1);

	Point southWest(location.x + 1, location.y + 1);

	

	//---------north------------//

	positions.push_back(north);

	positions.push_back(northEast);

	positions.push_back(northWest);

	//---------east------------//

	positions.push_back(east);

	//---------west------------//

	positions.push_back(west);

	//---------south------------//

	positions.push_back(south);

	positions.push_back(southEast);

	positions.push_back(southWest);

}

/*****************************************************************
	* Description:		gridIndex
	*					
	* 
	* Returns:			
	*
	* Parameters:		int x, int y;
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

int gridIndex( int x, int y )
{

	return y * width_g + x;

}

/*****************************************************************
	* Description:		gridIndex
	*					
	* 
	* Returns:			
	*
	* Parameters:		PointBase p
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

int gridIndex( PointBase p )
{

	return p.y * width_g + p.x;

}
/*****************************************************************
	* Description:		gridIndex
	*					
	* 
	* Returns:			grid point
	*
	* Parameters:		int i
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

char getChar( int i )
{

	return grid[i];

}
/*****************************************************************
	* Description:		getChar
	*					
	* 
	* Returns:			grid point in char
	*
	* Parameters:		int x, int y;
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

char getChar( PointBase point )
{

	int i = gridIndex(point);

	return grid[i];

}
/*****************************************************************
	* Description:		setChar
	*					
	* 
	* Returns:			NIL
	*
	* Parameters:		PointBase point, char c
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

void setChar( PointBase point, char c )
{

	int i = gridIndex(point);

	grid[i] = c;

}
/*****************************************************************
	* Description:		setChar
	*					
	* 
	* Returns:			NIL
	*
	* Parameters:		int x, int y, char c
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

void setChar( int x, int y, char c )
{

	int i = gridIndex(x, y);
	grid[i] = c;

}
/*****************************************************************
	* Description:		getChar
	*					
	* 
	* Returns:			point location
	*
	* Parameters:		int x, int y;
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

char getChar( int x, int y )
{

	int i = gridIndex(x, y);
	return grid[i];

}
/*****************************************************************
	* Description:		removeBadPoints
	*					remove 
	*					
	* 
	* Returns:			Nil
	*
	* Parameters:		std::vector<Point>& points, char objectiveNum
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

void removeBadPoints(std::vector<Point>& points, char objectiveNum)
{
	for (int i = points.size() - 1; i >= 0; i--)
	{
		PointBase point = points[i];

	
		if (point.x >= 0 && point.x < width_g && point.y >= 0 && point.y < height_g) 										// if inbounds
		{
			
			char c = getChar(point);																						// free space or char
			if (c == ' ' || c == objectiveNum)
				continue; // Don't remove
		}
		points.erase(points.begin() + i); // Remove all other pointNew
	}
}

/*****************************************************************
	* Description:		clearFastest
	*					
	* 
	* Returns:			liftNode(fastest, objective);
	*
	* Parameters:		std::vector<Point>& points, NodePoint objective
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

NodePoint clearFastest(std::vector<Point>& points, NodePoint objective)
{
	int fastestIndex = 0;

	int fastestDistance = width_g*width_g*height_g*height_g;

	for ( int i = 0; i < points.size(); i++ )
	{
		Point p = points[i];

		int dx; 
		int dy;

		dx = objective.x - p.x;
		dy = objective.y - p.y;


		int distance = dx*dx + dy*dy;

		if (distance < fastestDistance)
		{
			fastestIndex = i;
			fastestDistance = distance;
		}
	}

	Point fastest = points[fastestIndex];

	points.erase(points.begin() + fastestIndex );

	return liftNode(fastest, objective);
}

/*****************************************************************
	* Description:		findPath
	*					Checks points visited if visited a dot 
	*					is placed next position is checked and dot replaced with a dot.
	* 
	* Returns:			True or False
	*
	* Parameters:		NodePoint current, NodePoint objective
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

bool findPath(NodePoint current, NodePoint objective)
{
	// Base condition (end recursion)
	if (current == objective)

		return true;

	// Add dot to visited point
	if (getChar(current) != objective.number)
	{
		setChar(current, '.');
	}

																										// Checking nextpositions
	std::vector<Point> points;

	getPossiblePositions(current, points);

	removeBadPoints(points, objective.number);

																										
	while (!points.empty())
	{
		NodePoint next = clearFastest(points, objective);

		bool result = findPath(next, objective);

		
		if (result == true)
		{
			
		if (getChar(current) != objective.number)														// Letter replacing

		setChar(current, objective.letter);

		return true;

		}
	}

	return false;
}

/*****************************************************************
	* Description:		printGrid
	*					Prints the new grid.
	*					
	* 
	* Returns:			NIL
	*
	* Parameters:		NIL
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

void printGrid()
{
	for (int y = 0; y < height_g; y++)
	{
		std::cout << "Printing Grid" << std::endl;

		for (int x = 0; x < width_g; x++)
		{
			std::cout<< "showing characters " << getChar(x, y);
		}
	}
	std::cout << std::endl;
}

