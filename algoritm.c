#include <cmath>

//include everything
int findPath(int targetX, int targetY, int myX, int myY, int &board[][][], int path[][], int pathIndex){
	//see if we have gotten to the target location
	if(targetX == myX && targetY == myY){
		return 1;
	}

	//make sure we are inside the board
	if(myX < 0 || myX >= 4 || myY < 0 || myY >= 4)
		return 0;
	//check north, then south, then east, then west

	//check south
	if(board[myX][myY - 1][1] == 1){
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
	if(board[myX + 1][myY][1] == 1){
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
	if(board[myX - 1][myY][1] == 1){
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
	if(board[myX][myY + 1][1] == 1){
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

void markBoard(int x, int y, int thing, int &board[][][]){
	//when only 1 adjactent thing
	//if a spot is already known as safe, do not mark it otherwise
	if(x > 0 && board[x-1][y][1] == 0){
		//mark west
		board[x-1][y][thing] = 1;
		for(int i = 2; i < 5; i++)
			if (i != thing)
				board[x-1][y][i] = 0;
	}
	if(x < 3 && board[x+1][y][1] == 0){
		//mark east
		board[x+1][y][thing] = 1;
		for(int i = 2; i < 5; i++){
			if(i != thing)
				board[x+1][y][i] = 0;
		}
	}
	if(y > 0 && board[x][y-1][1] == 0){
		//mark north
		board[x][y-1][thing] = 1;
		for(int i = 2; i < 5; i++){
			if(i != thing)
				board[x][y-1][i] = 0;
		}
	}
	if(y < 3 && board[x][y+1][1] == 0){
		//mark south
		board[x][y+1][thing] = 1;
		for(int i = 2; i < 5; i++){
			if(i != thing)
				board[x][y+1][i] = 0;
		}
	}
	//mark this spot as visted
	board[x][y][0] = 1;
}

void markBoard(int x, int y, int ob1, int ob2, int &board[][][]){
	//for when 2 things are given
	if(x > 0 && board[x-1][y][1] == 0){
		//mark west
		board[x-1][y][ob1] = 1;
		board[x-1][y][ob2] = 1;
		for(int i = 2; i < 5; i++)
			if(i != ob1 && i != ob2)
				board[x-1][y][i] = 1;
	}
	if(x < 3 && board[x+1][y][1] == 0){
		//mark east
		board[x+1][y][ob1] = 1;
		board[x+1][y][ob2] = 1;
		for(int i = 2; i < 5; i++)
			if(i != ob1 && i != ob2)
				board[x+1][y][i] = 1;
	}
	if(y > 0 && board[x][y-1][1] == 0){
		//mark north
		board[x][y-1][ob1] = 1;
		board[x][y-1][ob2] = 1;
		for(int i = 2; i < 5; i++)
			if(i != ob1 && i != ob2)
				board[x][y-1][i] = 1;
	}
	if(y < 3 && board[x][y+1][1] == 0){
		//mark south
		board[x][y+1][ob1] = 1;
		board[x][y+1][ob2] = 1;
		for(int i = 2; i < 5; i++)
			if(i != ob1 && i != ob2)
				board[x][y+1][i] = 1;
	}

	//mark this spot as visted
	board[x][y][0] = 1;
}

void markBoard(int x, int y, int &board[][][]){
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

void clearOtherSpaces(int x, int y, board& int[][][], int object){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			//remove this possibility unless it is adjacent to the current square
			if(	i == x-1 && j == y ||
				i == x+1 && j == y ||
				i == x && j == y+1 ||
				i == x && j == y-1){

				board[i][j][object] = 0;
			}
		}
	}
}

void followPath(int &myX, int &myY, int[][] path, int endX, int endY, int &rotation){
	int pathCount = 0;
	while(myX != endX && myY != endY){
		//keep going

		//move
		if(myX - path[pathIndex][0] == 0 && myY - path[pathIndex][1] == 1){
			rotation = moveUp();
			myY++;
		}
		else if(myX - path[pathIndex][0] == 0 && myY - path[pathIndex][1] == -1){
			rotation = moveDown();
			myY--;
		}
		else if(myX - path[pathIndex][0] == 1 && myY - path[pathIndex][1] == 0){
			rotation = moveLeft();
			myX--;
		}
		else if (myX - path[pathIndex][0] == -1 && myY - path[pathIndex][1] == 0){
			rotation = moveRight();
			myX++;
		}
		else{
			//the path has a move that is not adjecent, oh no i have no idea what to do now
		}
		pathCount++;
	}
}

{
//make a 4x4 board, fill it properly
int init[5] = {0,0,1,1,1};

int board[4][4][5] = {
	{{1,1,0,0,0}, {0,1,0,0,0}, init, init}, 
	{{0,1,0,0,0}, init, init, init},
	{init, init, init, init},
	{init, init, init, init}
}
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


//start the full algorithm
while(1){
	//see if there is only 1 gold space
	int goldCount = 0;
	int i;
	int j;
	for(j = 0; j < 4; j++){
		for(i = 0; i < 4; i++){
			goldCount += board[i][j][3];
		}
	}
	if(goldCount == 1){
		//we have the location of the gold, find it and go to it
		int gX;
		int gY;
		for(j = 0; j < 4; j++){
			for(int i = 0; i < 4; i++){
				if(board[i][j][3] == 1){
					gX = i;
					gY = j;
					break;
				}
			}

			int[16][2] goldPath;
			findPath(gX, gY, myX, myY, board, goldPath, 0);
			followPath(myX, myY, goldPath, gX, gY, myDir);
			//go home
		}
	}
	else if(goldCount == 0){
		//something went horribly wrong, we should never do this
		//once the robot picked up the gold I think, might never even reach here
	}

	//see if there is only one location of the wumpus
	if(wumpusLives == 1){
		int wumpusCount = 0;
		for(j = 0; j < 4; j++){
			for(i = 0; i < 4; i++){
				wumpusCount += board[i][j][2];
			}
		}

		if(wumpusCount == 1){
			//we know the location of the wumpus, time to kill it
		}
	}

	//don't know the gold or the wumpus, time to go exploring!

	//find the nearest unvisited safe space

	float minDistance = 50.0f; //no idea if that's right
	int nearX;
	int nearY;
	for(j = 0; j < 4; j++){
		for(int i = 0; i < 4; i++){
			if(board[i][j][0] == 0 && board[i][j][1] == 1){
				//space is safe and unvisited
				//find the distance between current space and this space
				float dist = sqrt(pow(myX - i, 2) - pow(myY - j,2));
				if(minDistance > dist){
					minDistance = dist;
					nearX = myX;
					nearY = myY;
				}
			}
		}
	}

	//go to nearX, nearY

	//call find path
	int[16][2] path;
	findPath(nearX, nearY, myX, myY, board, path, 0);
	//follow that path
	followPath(myX, myY, path, nearX, nearY, myDir);

	//read the data
	int input;

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
		markBoard(myX, myY, 2, 4);
		clearOtherSpaces(myX, myY, board, 2);

		break;
		case 4:
		//near gold
		markBoard(myX, myY, 3, 1, board);
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
		int[16][2] homePath;
		findPath(0,0, myX, myY, board, homePath, 0);
		followPath(myX, myY, homePath, 0,0, myDir);


		break;
	}



}

}

