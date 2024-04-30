# Connect the Dots

https://private-user-images.githubusercontent.com/159634965/326730199-f6c8238b-3f58-4310-9462-33e5442ac663.mov?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTQ0NjcwOTcsIm5iZiI6MTcxNDQ2Njc5NywicGF0aCI6Ii8xNTk2MzQ5NjUvMzI2NzMwMTk5LWY2YzgyMzhiLTNmNTgtNDMxMC05NDYyLTMzZTU0NDJhYzY2My5tb3Y_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDMwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQzMFQwODQ2MzdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT01YTc4ZmFiZTdlMjM4MjFkNThmOWYwNmFhMGJlMjI0YWVjN2VhMTA5MjI0NzQ1ZmU0MjE0ZjIyOWY3YjVkZGZkJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.6j9Zg_TeP7SDcXS4hv5n-I9Xpgp6ifnJ8iETfKG2uRg

## Team members 🤖
Wong Man Yi (UID : 3036225058)

Yau Wing Sze (UID : 3036219267) 

## About this game 🪧
**Connet the Dots** is a puzzle game requiring player to connect integers in ascending and descending orders alternatively.

Integers are randomly displaced around a square-shaped board , player has to first connect them in ascending order,e.g. "1,2,3,4" , then in descending order, e.g. "1,2,3,4,3,2,1", and so on, until all the integers are being used.

Each integer is represented by a dot and each dot must be used once (and at most once). Interger to be connected cannot be from the same side as the previous dot.

## How to play 💬

The game is SUPER easy to play.

First, press the `'enter'` key to get into the game, then select the game mode you would like to play and get your game started!!

Your starting position will be at the dot in the top left corner. Press the `WASD` keys to navigate to other dots. Press the `'enter'` key to connect dots. A pop-up message will be shown when there is an invalid movement or incorrect connection. The 'progress' line above the board shows the current progress of the game and the integer to be connected next.

Press `'Q'` key to pause the game, a table will be displayed afterwards.
- `Return (Q)` --> return to the game  
- `Restart (R)` --> restart the game (with the same board) 
- `Start a New Game (N)` --> start a new game (with a different board)

## Features 🫵🏻
1. The integers around the board are generated randomly in each round.    *(Generation of random game sets)*
   
2. We used *int next* to access the number that should be connected next. The value of *next* will be increased by 1 after every successful connection. *string status* is used to end the game if the player wins/ loses/ quits and it will also be changed in case the player makes an invalid movement or incorrect connection.    *(Data structures for storing game status)*

3.  We used a vector to store all the dots that have been used / connected, to prevent the usage of the same dot twice and the player will win once the size of the vector equals to the total number of dots.    *(Dynamic memory management)*
4. The result’s message is stored in a text file for easy preview during design. Then we read from the text file to print the message out.    *(File input/output)*
5. Functions are stored in different files.    *(Program codes in multiple files)*

## Compilation and execution instructions 😝
1. Download the zip file
2. type `make ctd` command
3. type `./ctd` command
