
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
    T tmp = top();
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
  void pushUninvited(int x, int y);
  friend ostream &operator<<(ostream &, const Maze &);
  int rows, cols;
};

// Implementations for each maze fn
Maze::Maze() : entryMarker('m'), exitMarker('e'), visitedMarker('.'), moveableMarker('0'), wallMarker('1')
{
  Stack<char *> mazeRows;
  cout << "Enter each row followed by <C-n>" << endl;
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
  store
}

int main(int argc, char *argv[])
{

  return 0;
}
