///////////////////////////////////////////////////////////////////////////////////
// Filename:		main.cpp									 				//
// Author:			Elizabeth King												//
// Date Modified:	10/04/2015 													//
//																				//
///////////////////////////////////////////////////////////////////////////////////

#include "pointPoint.cpp"
#include "NodePoint.cpp"

int main()
{

	// Get filename

	char fileName[100] = "lizard.txt";
	

	std::ifstream inFile(fileName);

	if (inFile.is_open())
	{
		
		width_g = height_g = 0;

		char c;
		int i = 0;

		while ((c = inFile.get()) != EOF)
		{
			if (c == '\n')
			{
				if (width_g == 0)
					width_g = i;
			}
			else
			{
				grid[i++] = c;
			}
		}
		height_g = i / width_g;

		std::cout << "width:" << width_g << " height:" << height_g << std::endl;
	}
	else
	{
		std::cout << "Failed to open file: " << fileName;
	}

	std::vector<NodePoint> routes[10];

	// Find number of end points/routes
	for (int x = 0; x < width_g; x++)
	{

		for (int y = 0; y < height_g; y++)
		{

			int i = y * width_g + x;

			int num = grid[i] - '0';

			if (num >= 0 && num <= 9)
			{
				routes[num].push_back(NodePoint(x, y, grid[i], (char)('a' + num)));
			}
		}
	}

	std::cout << "The end points: " << std::endl;

	int routeCount = 0;

	for (int i = 0; i < 10; i++)
	{
		std::cout << routes[i].size() << "x" << i << ' ';

		if (routes[i].size() > 0)
		{
			routeCount++;
		}

			
	}
	std::cout << "Routes available: " << routeCount << std::endl;


	printGrid();
	// Search for a legal path for each route
	for (int i = 0; i < 10; i++)
	{
		std::vector<NodePoint> route = routes[i];

		if (route.size() > 0)
		{
			bool result = findPath(route[0], route[1]);
		}

			
	}
	printGrid();
	
	getchar();
}