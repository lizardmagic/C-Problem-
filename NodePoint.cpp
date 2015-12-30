
#include "pointPoint.cpp"

class NodePoint : public PointBase
{
public:
	char number, letter;
	bool visited;

	/*****************************************************************
	* Description:		NodePoint Constructor
	*  
	* Returns:			NIL
	*
	* Parameters:		int x, int y, char numberChar, char letterChar) : PointBase(x, y)
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

	NodePoint(int x, int y, char numberChar, char letterChar) : PointBase(x, y)
	{

		number = numberChar;
		letter = letterChar;
		
		visited = false;
	}


private:

};

	/*****************************************************************
	* Description:		PointBase= Constructor
	*  
	* Returns:			NIL
	*
	* Parameters:		int xPoistion, int yPosition
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/


class Point : public PointBase
{
public:
	Point(int x, int y) : PointBase(x, y) {};
	Point(const NodePoint& other) : PointBase(other.x, other.y) {};

private:

};

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

class NodePoint : public PointBase
{
public:
	char number, letter;
	bool visited;

	NodePoint(int x, int y, char numberChar, char letterChar) : PointBase(x, y)
	{
		number = numberChar;
		letter = letterChar;
		visited = false;
	}

	/*****************************************************************
	* Description:		liftNode
	*  
	* Returns:			NIL
	*
	* Parameters:		int xPoistion, int yPosition
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/


NodePoint liftNode(const Point point, const NodePoint info)
{
	NodePoint np(info);
	np.x = point.x;
	np.y = point.y;

	return np;
}

	/*****************************************************************
	* Description:		contains
	*  
	* Returns:			NIL
	*
	* Parameters:		int xPoistion, int yPosition
	* 
	* Preconditions:	NIL
	*
	* Postconditions:	NIL
	******************************************************************/

bool contains(std::vector<NodePoint> arr, NodePoint point)
{
	for (int i = 0; i < arr.size(); i++)

		if (point == arr[i])
		{
			
			return true;

		}

		else

			return false;

}