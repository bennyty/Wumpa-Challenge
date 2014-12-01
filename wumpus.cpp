#include <cmath>
#include <iostream>
#include <string>

//include everything

/*int checkDir(int*** board, int myX, int myY, int dX, int dY, int path[16][2], int pathIndex){
	if((myX + dX >= 0 && myX + dX <= 4 && myY + dY >= 0 && myY + dY <= 4) && board[mxX + dX][myY + dY][1] == 1){
		for(int c = 0; c < pathIndex; c++){
			if(path[c][0] == myX + dX && path[c][1] == myY + dY){
				return 0;
			}
		}
		return 1;
	}
	return 0;
}*/
int findPath(int targetX, int targetY, int myX, int myY, int*** &board, int path[16][2], int pathIndex){
	//optimize so that it looks towards the desitnation first
	//see if we have gotten to the target location
	std::cout << "round " << pathIndex << std::endl;

	
	std::cout << myX << ", " << myY << std::endl;
	

	if(targetX == myX && targetY == myY){
		//print the path please
		std::cout << "done, path is: \n";
		for(int i = 0 ; i < pathIndex; i++){
			std::cout << path[i][0] << ", " << path[i][1] << std::endl;
		}
		return 1;
	}

	

	//make sure we are inside the board
	if(myX < 0 || myX >= 4 || myY < 0 || myY >= 4)
		return 0;
	//check north, then south, then east, then west


	//check south



	if(myY > 0 && board[myX][myY - 1][1] == 1){
		//south is safe, make sure that we have not already visited it
		int alreadyVisited = 0;
		for(int i = 0; i < pathIndex; i++){
			if(path[i][0] == myX && path[i][1] == myY - 1){
				//already visited this path
				alreadyVisited = 1;
				break;
			}
		}
		//call function
		if(alreadyVisited == 0){
			path[pathIndex][0] = myX;
			path[pathIndex][1] = myY - 1;

			if(findPath(targetX, targetY, myX, myY - 1, board, path, pathIndex + 1) == 1)
				return 1;
		}
	}


	//check east
	if(myX < 3 && board[myX + 1][myY][1] == 1){
		//east is safe, make sure that we have not already visited it
		int alreadyVisited = 0;
		for(int i = 0; i < pathIndex; i++){
			if(path[i][0] == myX + 1 && path[i][1] == myY){
				//already visited this path
				alreadyVisited = 1;
				break;
			}
		}
		//call function
		if(alreadyVisited == 0){
			path[pathIndex][0] = myX + 1;
			path[pathIndex][1] = myY;

			if(findPath(targetX, targetY, myX + 1, myY, board, path, pathIndex + 1) == 1)
				return 1;
		}
	}

	//check west
	if(myX > 0 && board[myX - 1][myY][1] == 1){
		//west is safe, make sure that we have not already visited it
		int alreadyVisited = 0;
		for(int i = 0; i < pathIndex; i++){
			if(path[i][0] == myX - 1 && path[i][1] == myY){
				//already visited this path
				alreadyVisited = 1;
				break;
			}
		}
		//call function
		if(alreadyVisited == 0){
			path[pathIndex][0] = myX - 1;
			path[pathIndex][1] = myY;

			if(findPath(targetX, targetY, myX - 1, myY, board, path, pathIndex + 1) == 1)
				return 1;
		}
	}

	//check north
	if(myY < 3 && board[myX][myY + 1][1] == 1){
		//south is safe, make sure that we have not already visited it
		int alreadyVisited = 0;
		for(int i = 0; i < pathIndex; i++){
			if(path[i][0] == myX && path[i][1] == myY + 1){
				//already visited this path
				alreadyVisited = 1;
				break;
			}
		}
		//call function
		if(alreadyVisited == 0){
			path[pathIndex][0] = myX;
			path[pathIndex][1] = myY + 1;

			if(findPath(targetX, targetY, myX, myY + 1, board, path, pathIndex + 1) == 1)
				return 1;
		}
	}
}


void markBoard(int x, int y, int thing, int*** &board){
	//when only 1 adjactent thing
	//if a spot is already known as safe, do not mark it otherwise
	if(x > 0 && board[x-1][y][1] == 0){
		//mark west
		if(thing == 1)
			board[x-1][y][thing] = 1;
		for(int i = 2; i < 5; i++)
			if (i != thing)
				board[x-1][y][i] = 0;
	}
	if(x < 3 && board[x+1][y][1] == 0){
		//mark east
		if(thing == 1)
			board[x+1][y][thing] = 1;
		for(int i = 2; i < 5; i++){
			if(i != thing)
				board[x+1][y][i] = 0;
		}
	}
	if(y > 0 && board[x][y-1][1] == 0){
		//mark north
		if(thing == 1)
			board[x][y-1][thing] = 1;
		for(int i = 2; i < 5; i++){
			if(i != thing)
				board[x][y-1][i] = 0;
		}
	}
	if(y < 3 && board[x][y+1][1] == 0){
		//mark south
		if(thing == 1)
			board[x][y+1][thing] = 1;
		for(int i = 2; i < 5; i++){
			if(i != thing)
				board[x][y+1][i] = 0;
		}
	}
	//mark this spot as visted
	board[x][y][0] = 1;
	board[x][y][3] = 0;
}

void markBoard(int x, int y, int ob1, int ob2, int*** &board){
	//for when 2 things are given
	if(x > 0 && board[x-1][y][1] == 0){
		//mark west
		if(ob1 == 1)
			board[x-1][y][ob1] = 1;
		else if(ob2 == 1)
			board[x-1][y][ob2] = 1;
		for(int i = 2; i < 5; i++)
			if(i != ob1 && i != ob2)
				board[x-1][y][i] = 0;
	}
	if(x < 3 && board[x+1][y][1] == 0){
		//mark east
		if(ob1 == 1)
			board[x+1][y][ob1] = 1;
		else if(ob2 == 1)
			board[x+1][y][ob2] = 1;
		for(int i = 2; i < 5; i++)
			if(i != ob1 && i != ob2)
				board[x+1][y][i] = 0;
	}
	if(y > 0 && board[x][y-1][1] == 0){
		//mark north
		if(ob1 == 1)
			board[x][y-1][ob1] = 1;
		else if(ob2 == 1)
			board[x][y-1][ob2] = 1;
		for(int i = 2; i < 5; i++)
			if(i != ob1 && i != ob2)
				board[x][y-1][i] = 0;
	}
	if(y < 3 && board[x][y+1][1] == 0){
		//mark south
		if(ob1 == 1)
			board[x][y+1][ob1] = 1;
		else if(ob1 == 1)
			board[x][y+1][ob2] = 1;

		for(int i = 2; i < 5; i++)
			if(i != ob1 && i != ob2)
				board[x][y+1][i] = 0;
	}

	//mark this spot as visted
	board[x][y][0] = 1;
	board[x][y][3] = 0;
}

void markBoard(int x, int y, int*** &board){
	//case where we hear everything
	if(x > 0 && board[x-1][y][1] == 0){
		//mark west
		for(int i = 2; i < 5; i++){
			board[x-1][y][i] = 1;
		}
	}
	if(x < 3 && board[x+1][y][1] == 0){
		//mark east
		for(int i = 2; i < 5; i++){
			board[x+1][y][i] = 1;
		}
	}
	if(y > 0 && board[x][y-1][1] == 0){
		for(int i = 2; i < 5; i++){
			board[x][y-1][i] = 1;
		}
	}
	if(y < 3 && board[x][y+1][1] == 0){
		for(int i = 2; i < 5; i++){
			board[x][y+1][i] = 1;
		}
	}
}

void clearOtherSpaces(int x, int y,int*** &board, int object){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			//remove this possibility unless it is adjacent to the current square
			if(	!(i == x-1 && j == y) &&
				!(i == x+1 && j == y) &&
				!(i == x && j == y+1) &&
				!(i == x && j == y-1)) {

				board[i][j][object] = 0;
			}
			/*if((i == x && j != y+1) 
				)*/
		}
	}
}

int moveUp(){
	std::cout << "moved up\n";
	return 0;
}
int moveDown(){
	std::cout << "moved down\n";
	return 180;
}
int moveLeft(){
	std::cout << "moved left\n";
	return 270;
}
int moveRight(){
	std::cout << "moved right\n";
	return 90;
}

void followPath(int &myX, int &myY, int path[16][2], int endX, int endY, int &rotation){
	int pathCount = 0;
	std::cout << "try to go pathing!\n";
	std::cout << "destination: " << endX << ", " << endY << std::endl;
	std::cout << "my location: " << myX << ", " << myY << std::endl;
	while(myX != endX || myY != endY){
		std::cout << "path time number : " << pathCount << std::endl;
		std::cout << "go to: " << path[pathCount][0] << ", " << path[pathCount][1] << std::endl;
		//keep going

		//move
		if(myX - path[pathCount][0] == 0 && myY - path[pathCount][1] == -1){
			rotation = moveUp();
			myY++;
		}
		else if(myX - path[pathCount][0] == 0 && myY - path[pathCount][1] == 1){
			rotation = moveDown();
			myY--;
		}
		else if(myX - path[pathCount][0] == 1 && myY - path[pathCount][1] == 0){
			rotation = moveLeft();
			myX--;
		}
		else if (myX - path[pathCount][0] == -1 && myY - path[pathCount][1] == 0){
			rotation = moveRight();
			myX++;
		}
		else{
			//the path has a move that is not adjecent, oh no i have no idea what to do now
		}
		std::cout << "now at (" << myX <<"," << myY << ")\n";
		pathCount++;
	}
}

void printBoard(int*** board){
	std::string top(49, '*');
	std::cout << top << std::endl;
	for(int y = 3; y >= 0; y--){
		std::cout << "* ";
		for(int i = 0; i < 4; i++){
			for(int k = 0; k < 5; k++){
				std::cout << board[i][y][k] << " ";
			}
			std::cout << "* ";
		}
		std::cout << "\n";
		std::cout << top << std::endl;
	}
	//std::cout << top << std::endl;
}


int main() {
//make a 4x4 board, fill it properly
//int init[5] = {0,0,1,1,1};

/*int board[4][4][5] = {
	{{1,1,0,0,0}, {0,1,0,0,0}, init, init}, 
	{{0,1,0,0,0}, init, init, init},
	{init, init, init, init},
	{init, init, init, init}
}*/
	std::cout << "welcome to the wumpus world!\n";
int*** board = new int** [4];
for(int i = 0; i < 4; i++){
	board[i] = new int* [4];
	for(int j = 0; j < 4; j++){
		board[i][j] = new int[5];
		board[i][j][0] = 0;
		board[i][j][1] = 0;
		board[i][j][2] = 1;
		board[i][j][3] = 1;
		board[i][j][4] = 1;
	}
}

board[0][0][0] = 1;
board[0][0][1] = 1;
board[0][0][2] = 0;
board[0][0][3] = 0;
board[0][0][4] = 0;

board[1][0][0] = 0;
board[1][0][1] = 1;
board[1][0][2] = 0;
board[1][0][3] = 0;
board[1][0][4] = 0;

board[0][1][0] = 0;
board[0][1][1] = 1;
board[0][1][2] = 0;
board[0][1][3] = 0;
board[0][1][4] = 0;

std::cout << "board has been created!\n";
printBoard(board);
//x, y, boardstuff
//0 = visited
//1 = safe
//2 = wumpus
//3 = gold
//4 = pit

int wumpusLives = 1;

int myX = 0;
int myY = 0;
int myDir = 0;

int keepGoing = 1;
//std::cout << "REALY!\n";
//start the full algorithm
while(1){
	std::cout << "*****************************************************************************";
	//see if there is only 1 gold space
	int goldCount = 0;
	int i;
	int j;
	
	for(j = 0; j < 4; j++){
		for(i = 0; i < 4; i++){
			//goldCount += board[i][j][3];
			//std::cout << "adding goldCount at space " << i << ", " << j << std::endl;
			
			if(board[i][j][3] == 1)
				goldCount++;
		}
	}

	std::cout << "gold count: " << goldCount << std::endl;
	int asd;
	
	if(goldCount == 1){
		//we have the location of the gold, find it and go to it
		std::cout << "found the gold\n";

		int gX;
		int gY;
		for(j = 0; j < 4; j++){
			for(int i = 0; i < 4; i++){
				if(board[i][j][3] == 1){
					std::cout << "I see gold in the loops at: " << i << ", " << j << std::endl;
					gX = i;
					gY = j;
					break;
				}
			}
		}
		int goldPath[16][2];
			std::cout << "try to get the gold, at spot " << gX << ", " << gY << std::endl;
			findPath(gX, gY, myX, myY, board, goldPath, 0);
			followPath(myX, myY, goldPath, gX, gY, myDir);
			//go home

			findPath(0,0, myX, myY, board, goldPath, 0);
			followPath(myX, myY, goldPath, 0, 0, myDir);

			return 0;
	}
	else if(goldCount == 0){
		//something went horribly wrong, we should never do this
		//once the robot picked up the gold I think, might never even reach here
		std::cout << "time to go home\n";
		return 0;
	}

	std::cout << "searching for the wumpus\n";
	//int asd;
	//see if there is only one location of the wumpus
	if(wumpusLives == 1){
		int wumpusCount = 0;
		for(j = 0; j < 4; j++){
			for(i = 0; i < 4; i++){
				wumpusCount += board[i][j][2];
			}
		}
		std::cout << "wumpus count: " << wumpusCount << std::endl;
		

		if(wumpusCount == 1){
			//we know the location of the wumpus, time to kill it

			//figure out where the wumpus is, go to next to it, and kill it (make sure to face it)
			int wX;
			int wY;
			float minDistance = 50.0;
			for(int j = 0; j < 4; j++){
				for(int i = 0; i < 4; i++){
					if(board[i][j][2] == 1){
						wX = i;
						wY = j;
						break;
					}
				}
			}

			int wumpX;
			int wumpY;
			//found the location of the wumpus, now find out which space that is near the wumpus is best for slaying
			if(wX > 0 && board[wX-1][wY][1] == 1){
				float dist = sqrt(pow(myX - wX + 1, 2) + pow(myY - wY, 2));
				if(dist < minDistance){
					minDistance = dist;
					wumpX = wX - 1;
					wumpY = wY;
				}
			}
			if(wX < 3 && board[wX+1][wY][1] == 1){
				float dist = sqrt(pow(myX - wX - 1, 2) + pow(myY - wY, 2));
				if(dist < minDistance){
					minDistance = dist;
					wumpX = wX + 1;
					wumpY = wY;
				}
			}
			if(wY > 0 && board[wX][wY-1][1] == 1){
				float dist = sqrt(pow(myX - wX, 2) + pow(myY - wY + 1, 2));
				if(dist < minDistance){
					minDistance = dist;
					wumpX = wX;
					wumpY = wY - 1;
				}
			}
			if(wY < 3 && board[wX][wY+1][1] == 1){
				float dist = sqrt(pow(myX - wX, 2) + pow(myY - wY - 1, 2));
				if(dist < minDistance){
					minDistance = dist;
					wumpX = wX;
					wumpY = wY + 1;
				}
			}

			//now go to the space that is best for wumpus killing
			int wumpPath[16][2];
			findPath(wumpX, wumpY, myX, myY, board, wumpPath, 0);
			followPath(myX, myY, wumpPath, wumpX, wumpY, myDir);

			//do the kill action
			std::cout << "kill the wumpus at space " << wX << "," << wY << std::endl;

			//update board
			board[wX][wY][2] = 0;
			board[wX][wY][1] = 1;
			wumpusLives = 0;
		}
	}

	//don't know the gold or the wumpus, time to go exploring!

	//find the nearest unvisited safe space
	std::cout << "finding the distance to nearest exploring tile\n";
	//std::cin >> asd;
	float minDistance = 50.0f; //no idea if that's right
	int nearX;
	int nearY;
	for(j = 0; j < 4; j++){
		for(int i = 0; i < 4; i++){
			//std::cout << "board " << i << ", " << j << " sub 0: " 
			if(board[i][j][0] == 0 && board[i][j][1] == 1){
				//space is safe and unvisited
				//find the distance between current space and this space
				float dist = sqrt(pow(myX - i, 2) + pow(myY - j,2));
				std::cout << "distance is: " << dist << std::endl;
				//std::cin >> asd;
				if(minDistance > dist){
					std::cout << "found a new, shorter path at " << i << ", " << j << std::endl;
					minDistance = dist;
					nearX = i;
					nearY = j;
				}
			}
		}
	}
	std::cout << "try to go to space " << nearX << ", " << nearY << std::endl;

	//go to nearX, nearY
	
	std::cout << "go exploring\n";
	//call find path
	int path[16][2];
	//std::cin >> asd;

	findPath(nearX, nearY, myX, myY, board, path, 0); // GIVES SEGFAULT
	//follow that path
	//std::cin >> asd;
	std::cout << path[0][0] << ", " << path[0][1] << std::endl;
	followPath(myX, myY, path, nearX, nearY, myDir);
	//std::cin >> asd;

	//read the data
	std::cout << "give me data for " << myX << ", " << myY << "\n";
	int input;
	std::cin >> input;

	switch(input){
		case 0:
		//safe
		markBoard(myX, myY, 1, board);

		break;
		case 1:
		//near pit
		markBoard(myX, myY, 4, board);

		break;
		case 2:
		//near wumpus
		markBoard(myX, myY, 2, board);
		clearOtherSpaces(myX, myY, board, 2);

		break;
		case 3:
		//near pit and wumpus
		markBoard(myX, myY, 2, 4, board);
		clearOtherSpaces(myX, myY, board, 2);

		break;
		case 4:
		//near gold
		markBoard(myX, myY, 3, 1, board);
		//std::cout << "input into the board\n";
		//printBoard(board);
		clearOtherSpaces(myX, myY, board, 3);

		break;
		case 5:
		//near pit and gold
		markBoard(myX, myY, 3, 4, board);
		clearOtherSpaces(myX, myY, board, 3);

		break;
		case 6:
		//near gold and wumpus
		markBoard(myX, myY, 3, 2, board);
		clearOtherSpaces(myX, myY, board, 3);
		clearOtherSpaces(myX, myY, board, 2);

		break;
		case 7:
		//near pit, wumpus, and gold
		markBoard(myX, myY, board);
		clearOtherSpaces(myX, myY, board, 3);
		clearOtherSpaces(myX, myY, board, 2);

		break;
		default:
		//got the gold
		//move back home
		int homePath[16][2];
		findPath(0,0, myX, myY, board, homePath, 0);
		followPath(myX, myY, homePath, 0,0, myDir);
		//keepGoing = 0;
		return 0;


		break;
	}
	std::cout << "did the thing\n";
	printBoard(board);
	//std::cin >> asd;


}

}

