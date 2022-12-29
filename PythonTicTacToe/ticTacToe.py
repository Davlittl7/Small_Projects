def drawBoard(drawnBoard):
  for row in range(3):
    print(drawnBoard[row])


playerOneMark = input("Please choose X or O player 1: ")

playerTwoMark = ''
if playerOneMark == 'X':
  playerTwoMark = 'O'
else:
  playerTwoMark = 'X'

print("So player two will be the other option!")

board = []
for row in range(3):
  board.append([""] * 3)

drawBoard(board)


def isValid(row, col):
  #if not allows program to exit early
  if row >= 0 and row < 3 and col >= 0 and col < 3:
    return True
  else:
    return False


def playerMakeMove(mark):
  isValidMove = False
  while not isValidMove:
    inputRow = int(input("Please select a Row: "))
    inputColumn = int(input("Please select a Column: "))

    #need to cast string values to be integer
    isValidMove = isValid(inputRow, inputColumn)
    if not isValidMove:
      print("Please input a proper move!")

  board[inputRow][inputColumn] = mark

def checkHorizontal():
  for row in range(3):
    mark = board[row][0]
    if mark == "":
      continue

    matches = 1
    for col in range(1, 3):
      if mark == board[row][col]:
        matches += 1
    
    if matches == 3:
      return True

  return False

def checkVertical():
  for col in range(3):
    mark = board[0][col]    
    if mark == "":
      continue

    matches = 1
    for row in range(1, 3):
      if mark == board[row][col]:
        matches += 1

    if matches == 3:
      return True

  return False

def diagonal(row, col, increment):
  mark = board[row][col]
  if mark == "":
    return False
  
  matches = 1
  for _ in range(2):
    row += increment
    col += increment
    if mark == board[row][col]:
      matches += 1
  
  return matches == 3

def checkDiagonal():
  return diagonal(0, 0, 1) or diagonal(0, 2, -1)



def checkWinner():
  return checkVertical() or checkHorizontal() or checkDiagonal()


def checkBoardFilled():
  for row in range(3):
    for col in range(3):
      if board[row][col] == "":
        return False
  return True

def TicTacToe():
  while True:
    for mark in [playerOneMark, playerTwoMark]:
      playerMakeMove(mark)
      drawBoard(board)
      if checkWinner(): 
        print(mark, "wins!")
        return
  
      if checkBoardFilled():
        print("Draw!")
        return 
      

TicTacToe()
