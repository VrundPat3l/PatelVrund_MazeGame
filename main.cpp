#include <iostream>                                                                    
#include <time.h>                                                                      
#include <conio.h>                                                                     
using namespace std;  

// Declaring Constant variable in Mazesize for map                                                                                        
constexpr int MazeSize = 9;

// Creating Maze Map Using 2D Array                                                                   
char maze[MazeSize][MazeSize] = {                                                       
    {'#', '#', '#', '#', '#', '#', '#', '#', '#'},                                      
    {'#', '.', '.', '.', '.', '^', '.', '.', '#'},                                      
    {'#', '.', '#', '*', '#', '.', '#', '.', '#'},                                      
    {'#', '.', '$', '#', '#', '.', '#', '*', '#'},                                      
    {'#', '.', '#', '#', '.', '^', '#', '#', '#'},                                      
    {'#', '#', '#', '#', '.', '#', '$', '#', '#'},                                      
    {'#', '.', '.', '^', '.', '.', '.', '*', '#'},                                      
    {'#', '.', '#', '#', '#', '$', '#', '#', '#'},                                      
    {'#', 'X', '#', '#', '#', '#', '#', '#', '#'}                                       
};                                                                                      
// Players position                                                                     
int playerX = 1;                                                                        
int playerY = 1;
// Moving Enemy Initial Position and it will move Random with user's input
int EnemyX = 1;
int EnemyY = 4;
// Declaring int score variable to store the score
int score = 0;      
// Declaring bool variables to check if they have abilities to kill and break
bool CanKillEnemies = false;                                                            
bool CanBreakWall = false;                                                              
bool AbilityUsed = false;                                                               

// Created a function to print maze
void PrinMaze(int Random)                                                               
{                                                                                      
    system("cls");                                                                      // To clear the screen before printing maze/array for realtime update
    for (int i = 0; i < MazeSize; i++)                                                  // Using for loop to print Row of the maze
    {                                                                                   
        for (int j = 0; j < MazeSize; j++)                                              // Using for loop to print Column of the maze
        {                                                                               
            if (i == playerY && j == playerX)                                           // Condition if i and j is 1 (Player's position(x,y))
            {                                                                           
                cout << "@";                                                            // then print player at position (1,1)
            }     
            else if (i == EnemyY && j == EnemyX)                                        // Condition if i and j is 1 (Player's position(x,y))
                 {
                   cout << "^";                                                         // then print player at position (1,1)
                 }
            else                                                                        
            {                                                                           
                cout << maze[i][j];                                                     // Else print the maze
            }                                                                           
                                                                                     
            if (maze[playerY][playerX] == '#')                                          // Condition if player '@' is on '#'
            {                                                                           
                CanBreakWall = false;                                                   // then value of bool CanBreakWall is false
            }                                                                           
            if (maze[playerY][playerX] == '^')                                          // Condition if player '@' is on '^'
            {                                                                           
                CanKillEnemies = false;                                                 // then value of bool CanBreakWall is false
                maze[playerY][playerX] = '.';                                           // And print '.' there
            }                                                                           
            if (!AbilityUsed)                                                           // Condition if player has not used the ability, AbilityUsed is flase 
            {    
                if (Random == 3)
                {
                    maze[Random][Random] = '&';                                         // then print '$' at (3,3)
                    AbilityUsed = true;                                                 // And change the value of bool AbilityUsed to true
                }
            }                                                                           
        }                                                                               
        cout << "\n";                                                                   // line break after printing every Row
    }                                                                                   
}                                                                                       
                                                                                        
                                                                                        
// Creating function for Printing Rules                                                                                       
void IntroAndRules()                                                                    
{                                                                                       
    cout << "                                    Welcome To Maze Game \n";              
    cout << "Rules: \n";                                                                
    cout << "- To Play the Game Use w a s d  on your keyboard to control '@' \n";       
    cout << "- You cant walk out through walls '#' \n";                                 
    cout << "- Collect '$' to gain 5 points \n";                                        
    cout << "- Collect '*' to get ability to kill enemies \n";                          
    cout << "- Kill '^' Enemies to gain 10 points \n";                                  
    cout << "- Collect Randomly generated '&' to get ability to break a wall \n";       
    cout << "- You can break only 1 wall with '&' ability \n";                          
    cout << "- To win the game you nee to find a path to X exit \n";                    
    system("pause");                                                                    // To give a pause in the code and it will continue if user hit's enter 
}                                                                                       

// Creating function to update the score and values
void UpdateScore()                                                                      
{                                                                                       
                                                                                   
    else if (maze[playerY][playerX] == '*')                                             // else if player is on '*' 
    {                                                                                   
        CanKillEnemies = true;                                                          // then chnage the value of bool to true
    }                                                                                   
    else if (maze[playerY][playerX] == '^')                                             // if player is on '^'
    {                                                                                   
        score += 10;                                                                    // then update the score add 10 to it
    }                                                                                   
    else if (maze[playerY][playerX] == '&')                                             // if player is on '&'
    {                                                                                   
        CanBreakWall = true;                                                            // then chnage the value of bool to true
    }                                                                                   
    else if (maze[playerY][playerX] == 'X')                                             // if Player is on 'X'
    {                                                                                   
        score += 55;                                                                    // then update the score add 55 to it
    }                                                                                   
}                                                                                       
      
// Creating a function to congratulate player if he reach to 'X'
void Congrats(int Random)                                                               
{                                                                                       
    PrinMaze(Random);                                                                   // Printing final map/Array
    cout << "\n";                                                                       
    cout << "your Score is " << score << "\n";                                          
    cout << "\n";                                                                       
    cout << "Congratulations! you find the way out, you win";                           
    cout << "\n";                                                                       
}                                                                                       

// Creating function to print error if player is near to enemy '^' and does not have ability to kill  
void PrintError()                                                                       
{                                                                                       
    if (maze[playerY][playerX + 1] == '^' || maze[playerY - 1][playerX] == '^'          // Condition if player is near/around the enemy '^'
       || maze[playerY][playerX - 1] == '^' || maze[playerY + 1][playerX] == '^')       
    {                                                                                   
        if (CanKillEnemies == false)                                                    // Nested condition if CanKillEnemies is flase
        {                                                                               
            cout << "you need to kill enemy to go ahead\n";                             // then print the error message
            cout << "Go back and Collect '*' to kill enemies\n";                        
        }                                                                               
    }                                                                                   
}                   

// Creating Function for Game loop with variable int Random
void GameLoop(int Random)                                                               
{                                                                                       
    while (maze[playerY][playerX] != 'X')                                               // Creating a loop to iterate until the condition if player '@' is not on 'X'
    {                                                                                   
        PrinMaze(Random);                                                               // Printing the maze/2D Array Calling Printmaze() function
        cout << "\n";                                                                   // line break
        cout << "your Score is " << score << "\n";                                      // Printing the score
        PrintError();                                                                   // Calling the function PrintError() to print error message
        char input = _getch();                                                          // Declaring char variable input and get input from his keyboard
        switch (input)                                                                  // Creating a Switch with variable char input
        {                                                                               
        case 'w':                                                                       // case 'w' if player hit w on his keyboard
            if (maze[playerY - 1][playerX] != '^' || CanKillEnemies)                    // Condition to check if there is a enemy '^' upwards(If player is at (1,1) then checking is there a '^' at (0,1)) and CanKillEnemies is true
            {                                                                           
                if (maze[playerY - 1][playerX] != '#' || CanBreakWall)                  // Condition to check if there is a Wall '#' upwards(If player is at (1,1) then checking is there a '#' at (0,1)) and CanBreakWall is true
                {
                    if (playerY - 1 != 0)
                    {
                        playerY--;                                                      // if all condition is passed/yes then changing playerY's value (-1) to it
                    }
                    if (maze[EnemyY + 1][EnemyX] != '#')                                // Condition for moving enemy if there is wall '#' on the way
                    {
                        EnemyY++;                                                       // if no then enemy will move one position in y direction
                    }
                    else 
                    {
                        EnemyY--;                                                       // else if yes then it will move back one position in y direction
                    }
                
                }
            }                                                                           
            break;                                                                      // to break the case
        case 's':                                                                       // case 's' if player hit w on his keyboard
            if (maze[playerY + 1][playerX] != '^' || CanKillEnemies)                    // Condition to check if there is a enemy '^' upwards(If player is at (1,1) then checking is there a '^' at (2,1)) and CanKillEnemies is true
            {   
                if (maze[playerY + 1][playerX] != '#' || CanBreakWall )                 // Condition to check if there is a Wall '#' upwards(If player is at (1,1) then checking is there a '#' at (2,1)) and CanBreakWall is true
                {
                    playerY++;
                    if (maze[EnemyY + 1][EnemyX] != '#')                                // Condition for moving enemy if there is wall '#' on the way
                    {
                        EnemyY++;                                                       // if no then enemy will move one position in y direction
                    }
                    else
                    {
                        EnemyY--;                                                       // else if yes then it will move back one position in y direction
                    }
                    
                }
            }                                                                           
            break;                                                                      // to break the case
        case 'a':                                                                       // case 'a' if player hit w on his keyboard
            if (maze[playerY][playerX - 1] != '^' || CanKillEnemies)                    // Condition to check if there is a enemy '^' upwards(If player is at (1,1) then checking is there a '^' at (1,0)) and CanKillEnemies is true
            {                                                                           
                if (maze[playerY][playerX - 1] != '#' || CanBreakWall)                  // Condition to check if there is a Wall '#' upwards(If player is at (1,1) then checking is there a '#' at (1,0)) and CanBreakWall is true
                {
                    if (playerX - 1 != 0)
                    {
                        playerX--;                                                          // if all condition is passed/yes then changing playerX's value (-1) to it
                    }
                    if (maze[EnemyY + 1][EnemyX] != '#')                                // Condition for moving enemy if there is wall '#' on the way
                    {
                        EnemyY++;                                                       // if no then enemy will move one position in y direction
                    }
                    else
                    {
                        EnemyY--;                                                       // else if yes then it will move back one position in y direction
                    }
                    
                }
            }                                                                           
            break;                                                                      // to break the case
        case 'd':                                                                       // case 'd' if player hit w on his keyboard
            if (maze[playerY][playerX + 1] != '^' || CanKillEnemies)                    // Condition to check if there is a enemy '^' upwards(If player is at (1,1) then checking is there a '^' at (1,2)) and CanKillEnemies is true
            {                                                                           
                if (maze[playerY][playerX + 1] != '#'  || CanBreakWall)                 // Condition to check if there is a Wall '#' upwards(If player is at (1,1) then checking is there a '#' at (1,2)) and CanBreakWall is true
                {
                    if (playerX + 1 != 8)
                    {
                        playerX++;                                                      // if all condition is passed/yes then changing playerX's value (+1) to it
                    }
                    if (maze[EnemyY + 1][EnemyX] != '#')                                // Condition for moving enemy if there is wall '#' on the way
                    {
                        EnemyY++;                                                       // if no then enemy will move one position in y direction
                    }
                    else
                    {
                        EnemyY--;                                                       // else if yes then it will move back one position in y direction
                    }
                    
                }
            }                                                                           
            break;                                                                      // to break the case
        default:                                                                        
            cout << "Use W A S D to play the Game";                                     // default condition for switch if pressed anyother key rather then w a s d
            break;                                                                      // to break the case // optional because its default and last case so its not necessary to break it
        }                                                                               
        UpdateScore();                                                                  // Calling UpdateScore() function
    }                                                                                   
    Congrats(Random);                                                                   // Calling Congrats() function
}                                                                                       
                                                                                        
// Main Function                                                                                        
int main()                                                                              
{                                                                                       
    srand((unsigned)time(nullptr));                                                     // Seeding random number
    int Random = 1 + rand() % 3;                                                        // Declaring Random variable and assigning value to it
    IntroAndRules();                                                                    // Calling IntroAndRules() function
    GameLoop(Random);                                                                   // Calling GameLoop() function
    return 0;                                                                           // Exits the code with zero error
}