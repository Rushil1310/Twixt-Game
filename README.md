# A Twixt game 
### - Rushil Sharma 2025114009
## Running the game:
  To run the game we open terminal in which these 4 files are there and then we use the following commands:<br/>
    ```>make``` <br/>
    ```>./a.exe```
## Interface of the game:
  This game is designed as an array of characters where:<br/>
    **'.' = empty space**<br/>
    And players input a CAPITAL LETTER in the start to denote their node.<br/>
    The nodes are in **Red** and **Green**<br/>
> If there is interlinking between two nodes they become small char of the same letter
> Like this ![Initial image](https://github.com/cpro-iiit/course-project-phase-2-Rushil1310/blob/main/Pictures/next.png?raw=true) ![Final image](https://github.com/cpro-iiit/course-project-phase-2-Rushil1310/blob/main/Pictures/prev.png?raw=true)
## Checking conditions
I have a checking condtions function which does the following:
  Looks at all possible places with which the link can be made, If found then it runs a check function <br/>
  To check overlapping, we check for a ```small letter``` in the 2x3 box of the 2 Nodes which may Link <br/>
  There will be 2 cases for this.
    > The case in which the ```small letter``` is linked to its other ```small letter``` and the mid-point of both lie inside of that 2x3 space <br/>
    > The case in which the midpoint is not inside the 2x3 space 
  Only in the second case, will the link be made and the letter be converted to small ***to represent a link*** <br/>
  ![Check](https://github.com/cpro-iiit/course-project-phase-2-Rushil1310/blob/main/Pictures/checkfun.png?raw=true) <br/>
  ## Checking winning condition
  The win condition is checked by following all links from the top all the way to the bottom by DFS ```Depth first search``` <br/>
  And then all the visited sites are marked by a -1 to avoid looping indfinitly <br/> 
  Finnaly if we reach the end of the box we declare the winner <br/>
