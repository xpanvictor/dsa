
#include <iostream>
#include <string>
#include <stack>
#include <string.h>

using namespace std;

template <class T>
class Stack : public stack<T>
{
public:
  T pop()
  {
    T tmp = this->top();
    stack<T>::pop();
    return tmp;
  }
};

class Cell
{
public:
  Cell(int i = 0, int j = 0)
  {
    x = i;
    y = j;
  }

  bool operator==(const Cell &c) const
  {
    return x == c.x && y == c.y;
  }

private:
  int x, y;
  friend class Maze;
};

class Maze
{
public:
  Maze();
  void exitMaze();

private:
  Cell exitCell, entryCell, currentCell;
  const char exitMarker, visitedMarker, entryMarker, moveableMarker, wallMarker;
  Stack<Cell> mazeStack;
  char **store; // Array of array of chars .i.e array of strings
  // utility functions
  void pushUnvisited(int x, int y);
  friend ostream &operator<<(ostream &, const Maze &);
  int rows, cols;
};

// Implementations for each maze fn
Maze::Maze() : entryMarker('m'), exitMarker('e'), visitedMarker('.'), moveableMarker('0'), wallMarker('1')
{
  Stack<char *> mazeRows;
  cout << "Enter a rectangular maze using the following "
       << "characters:\nm - entry\ne - exit\n1 - wall\n0 - passage\n"
       << "Enter one line at at time; end with Ctrl-z:\n";
  char str[80], *s;
  int col, row = 0;

  while (cin >> str)
  {
    row++;
    cols = strlen(str);
    s = new char[cols + 3];
    mazeRows.push(s);
    strcpy(s + 1, str);
    s[0] = s[col + 1] = wallMarker;
    s[col + 2] = '\n';

    // fixing in entry and exit Cells
    char *exitMarkerIndexIfFound = strchr(s, exitMarker);
    if (exitMarkerIndexIfFound != 0)
    {
      exitCell.x = row;
      exitCell.y = exitMarkerIndexIfFound - s;
    }
    char *entryMarkerIndexIfFound = strchr(s, entryMarker);
    if (entryMarkerIndexIfFound != 0)
    {
      entryCell.x = row;
      entryCell.y = entryMarkerIndexIfFound - s;
    }
  }

  rows = row;
  store = new char *[rows + 2];
  // top layer of walls
  store[0] = new char[cols + 3];
  for (; !mazeRows.empty(); row--)
  {
    store[row] = mazeRows.pop(); // fill in store rows-1 to 1
  }
  // lower layer of walls
  store[rows + 1] = new char[cols + 3];
  // mark end of each wall row with term char
  store[0][cols + 2] = store[rows + 1][cols + 2] = '\0';
  // fill border line rows with walls
  for (col = 0; col <= cols + 1; col++)
  {
    store[0][col] = wallMarker;
    store[rows + 1][col] = wallMarker;
  }
}

void Maze::pushUnvisited(int x, int y)
{
  if (store[x][y] == moveableMarker || store[x][y] == exitMarker)
  {
    // then can add to unvisited stack
    mazeStack.push(Cell(x, y));
  }
}

// Now the algorithm for exiting a maze
void Maze::exitMaze()
{
  int cx, cy = currentCell.x;
  cy = currentCell.y;

  while (!(currentCell == exitCell))
  {
    store[cx][cy] = visitedMarker;
    // checking neighbors
    // left
    pushUnvisited(cx - 1, cy);
    // right
    pushUnvisited(cx + 1, cy);
    // top
    pushUnvisited(cx, cy - 1);
    // lower
    pushUnvisited(cx, cy + 1);

    // error out if mazeStack is empty
    if (mazeStack.empty())
    {
      cout << *this;
      cout << "No solution";
      throw std::invalid_argument("No solution for this maze");
    }
    currentCell = mazeStack.pop();
    cout << *this;
    cout << "Successfully found exit";
  }
}

ostream &operator<<(ostream &out, const Maze &maze)
{
  for (int row = 0; row <= maze.rows + 1; row++)
    out << maze.store[row] << endl;
  out << endl;
  return out;
}

int main(int argc, char *argv[])
{
  Maze().exitMaze();
  return 0;
}
