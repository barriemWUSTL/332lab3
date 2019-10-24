Mustapha Barrie Lab 3

One thing to note is that the rows are on the y axis and the columns are on the x axis 
so if you were to do the x,y coordinate system it would be (row, col) so something like 2,1 
would not be the same as the standard 2,1 in a (col,row) implementation

THe errors I had for the most part where files not being able to make functions or access structs from other files 
because I forget to put them at the top of the header file including

To test the not enough command line arguments I just used lab3.exe and it promopts you to type in the following into your
console to run the program "Lab3.exe TicTacToe"

To test user coordinate input things such as bad fromats, duplicates and other things I did,
Type coordinates in csv format to place a gamepiece or type quit to end the game
Invalid coordinates, please reenter
Type coordinates in csv format to place a gamepiece or type quit to end the game
asdssdsf
Invalid coordinates, please reenter

Type coordinates in csv format to place a gamepiece or type quit to end the game
2,1
Type coordinates in csv format to place a gamepiece or type quit to end the game
1,2
4
3  
2 OO
1  O
0
 01234

Player O: 2, 2; 2, 1; 1, 2;
X's turn

My implementation also tested out all the possible ways a game could end and my done and draw functions operate as they should.
If the board is filled, or there is three in a row in a row or column or diagnol the game will thus end.

My implementation of quit also works too if you were to do:
Type coordinates in csv format to place a gamepiece or type quit to end the game
quit
X quit the game in 1 turns!
