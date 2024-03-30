
#include <iostream>
#include <ostream>
using namespace std;

class ChessBoard
{
public:
  ChessBoard ();
  ChessBoard (int);
  void findSolutions ();

private:
  int squares, norms;
  void markMembersAvailability (bool);
  void initializeBoard ();
  const bool available;
  bool *columns, *leftDiagonals, *rightDiagonals;
  int *positionInRow, howMany;
  void putQueen (int);
  void printBoard (ostream &);
};

ChessBoard::ChessBoard () : available (true), squares (8), norms (squares - 1)
{
  initializeBoard ();
}
ChessBoard::ChessBoard (int n) : available (true), squares (n), norms (n - 1)
{
  initializeBoard ();
};

void
ChessBoard::initializeBoard ()
{
  int i;
  positionInRow = new int[squares];
  columns = new bool[squares];
  leftDiagonals = new bool[squares * 2 - 1];
  rightDiagonals = new bool[squares * 2 - 1];
  // Initializing the positions on the board
  for (i = 0; i < squares; i++)
    {
      positionInRow[i] = -1;
      columns[i] = available;
    }
  // setting all diagonals to available
  for (i = 0; i < (squares * 2) - 1; i++)
    {
      leftDiagonals[i] = rightDiagonals[i] = available;
    }
  cout << "Init: " << rightDiagonals[3] << rightDiagonals[6] << endl;
  howMany = 0;
}

void
ChessBoard::printBoard (ostream &out)
{
  for (int row = 0; row < squares; row++)
    {
      cout << "(" << row << ", " << positionInRow[row] << "), ";
    }
  cout << endl;
}

void
ChessBoard::putQueen (int row)
{
  for (int col = 0; col < squares; col++)
    {
      // check for availability of position
      if (columns[col] == available && leftDiagonals[row + col] == available
          && rightDiagonals[row - col + norms] == available)
        {
          positionInRow[row] = col;
          columns[col] = !available;
          leftDiagonals[row + col] = !available;
          rightDiagonals[row - col + norms] = !available;
          if (row < squares - 1)
            putQueen (row + 1);
          else
            {
              printBoard (cout);
              howMany++;
            }
          columns[col] = available;
          leftDiagonals[row + col] = available;
          rightDiagonals[row - col + norms] = available;
        }
    }
}

void
ChessBoard::findSolutions ()
{
  putQueen (0);
  cout << "Number of solutions: " << howMany << endl;
}

int
main (int argc, char *argv[])
{
  ChessBoard cb (4);
  cb.findSolutions ();
  return 0;
}
