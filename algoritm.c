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
	if(x > 0 && board[x-1][y][1] == 0){
		//mark west
		board[x - 1][y][thing] = 1;
		for(int i = 2; i < 5; i++)
			if (i != thing)
				board[x-1][y][i] = 0;
	}
	if(x < 4 && board[x+1][y][1] == 0){
		board[x+1][y][thing] = 1;
	}
	if(y > 0){
		board[x][y-1][thing] = 1;
	}
	if(y < 4){

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
	}
	else if(goldCount == 0){
		//something went horribly wrong, we should never do this
		//once the robot picked up the gold I think
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
	float minDistance = 50;
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

	//follow that path

	//read the data
	int input;

	switch(input){
		case 0:
		//safe


		break;
		case 1:
		//near pit

		break;
		case 2:
		//near wumpus

		break;
		case 3:
		//near pit and wumpus

		break;
		case 4:
		//near gold

		break;
		case 5:
		//near pit and gold

		break;
		case 6:
		//near gold and wumpus

		break;
		case 7:
		//near pit, wumpus, and gold

		break;
		/*case 8:
		//near gold

		break;
		case 10:
		//near gold and pit

		break;
		case 12:
		//near gold and wumpus

		break;
		case 14:
		//near gold, pit, wumpus

		break;*/
		default:
		//got the gold

		break;
	}



}

}

