#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<vector<int>> dirCoord
{
    {1 , 0},
    {-1 , 0},
    {0 , 1},
    {0 , -1}
};

enum Objects
{
    Start = 'S',
    Wall = '#',
    Free = '.',
    Finish = 'F'
};

struct Cell
{
    int row;
    int col;

    Cell(int x, int y) {
        this->row = x;
        this->col = y;
    }
};

Cell checkAdjCells(vector<string> &labyrinth, Cell curr, vector<int> &dir) {
    if (labyrinth[curr.row + dir[0]][curr.col + dir[1]] != Wall)
    {
        return Cell(curr.row + dir[0], curr.col + dir[1]);
    }
    return Cell(2000, 2000);
}

Cell checkFarCells(vector<string>& labyrinth, Cell curr, vector<int>& dir) {
    int steps = 1;
    while (labyrinth[curr.row + steps * dir[0]][curr.col + steps * dir[1]] != Wall)
    {
        steps++;
    }
    steps--;

    if (steps > 1)
    {
        return Cell(curr.row + steps * dir[0], curr.col + steps * dir[1]);
    }

    return Cell(2000, 2000);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    cin >> rows >> cols;

    vector<string> labyrinth(rows);
    for (int i = 0; i < rows; i++)
    {
        cin >> labyrinth[i];
    }

    queue<Cell> activeCells;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (labyrinth[i][j] == Start)
            {
                activeCells.push(Cell(i, j));
                break;
            }
        }
        if (activeCells.size() > 0)
        {
            break;
        }
    }

    int seconds = 0;
    while (activeCells.size() > 0)
    {
        int size = activeCells.size();
        for (int iter = 0; iter < size; iter++)
        {
            Cell curr = activeCells.front();
            if (labyrinth[curr.row][curr.col] == Finish)
            {
                cout << seconds;
                return 0;
            }
            else
            {
                labyrinth[curr.row][curr.col] = Wall;
            }

            for (int i = 0; i < 4; i++)
            {
                Cell newCell = checkAdjCells(labyrinth, curr, dirCoord[i]);
                if (newCell.row > rows || newCell.col > cols)
                {
                    continue;
                }
                activeCells.push(newCell);
            }

            for (int i = 0; i < 4; i++)
            {
                Cell newCell = checkFarCells(labyrinth, curr, dirCoord[i]);
                if (newCell.row > rows || newCell.col > cols)
                {
                    continue;
                }
                activeCells.push(newCell);
            }
            activeCells.pop();
        }
        seconds++;
    }

    cout << -1;
}