## Team members 🤖
Wong Man Yi (UID : 3036225058)

Yau Wing Sze (UID : 3036219267) 

## About this game 🪧
**Connet the Dots** is a puzzle game requiring player to connect integers in ascending and descending orders alternatively.

Integers are randomly displaced around a square-shaped board , player has to first connect them in ascending order,e.g. "1,2,3,4" , then in descending order, e.g. "1,2,3,4,3,2,1", and so on, until all the integers are being used.

Each integer is represented by a dot and each dot must be used once (and at most once). Consecutive intergers cannot be from the same side. 

## How to play 💬

The game is SUPER easy to play.

First,press the `'enter'` key to get into the game, then select the game mode you would like to play and get your game started!!

Your starting position will be at the dot in the top left corner. Press the `WASD` keys to navigate to other dots. Press the `'enter'` key to connect dots. A pop-up message will be shown when there is an invalid movement or incorrect connection. The 'progress' line above the square showes the current progress of the game and the integers to be connected next.

Press `'Q'` key to pause the game, a table will be displayed afterwards.
- `Return (Q)` --> return to the game  
- `Restart (R)` --> restart the game (with the same board) 
- `Start a New Game (N)` --> start a new game (with a different board)

## Features 🫵🏻
1. The integers around the boards are generated randomly in each round. *(Generation of random game sets)*
2. We used *int next* to access the number that should be connected next. The value of status will increased by 1 after every successful connection. *string status* is used to end the game if the player wins/loses/quits and it will also be changed in case the player makes an invalid movement or incorrect connection. *(Data structures for storing game status)*
3. We used a vector to store all the dots that have been used / connected, to prevent the usage of the same dot twice and the player will win once the size of the vector equals to the total number of dots. 
4. 
