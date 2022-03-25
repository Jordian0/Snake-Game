
# Snake Game

This is a simple snake game built using C++. Snake can move up, right, down, left. If snakes eats the fruit '@' then its length increases and score gets increased by 5 and if snake touches the wall of the game window or snake hit itself then game will be over.


<br/>
## Screenshots
<div style="margin-left:50px">

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)
</div>

<br/>
## How to play
You can press these keys to change the direction of the snake or to exit the game.
<div style="margin-left:50px">

| Key  | Direction  |
| -----| -----------|
| w    | UP         |
| s    | DOWN       |
| a    | LEFT       |
| d    | RIGHT      |
| x    | QUIT       |
</div>

<br/>
## Libraries we'll need

- [**conio.h**](https://en.wikipedia.org/wiki/Conio.h) : For console input and output. For windows systems you can download the file. For linux systems that file is in the repository.
- **uninst.h** : usleep() function in linux systems, to slow down the game. usleep() function suspends execution for microsecond intervals.
- **Windows.h** : Sleep() function in windows systems, to slow down the game. Sleep() function suspends execution for second intervals.

  **Other libraries are included in cpp files**
 
<br/>
## To run the game

First we have to compile the game :

```bash
  g++ *.cpp -o output
```
<br/>
To execute the compiled file run :

```bash
  ./output
```

<br/>
## UML Diagram


<div style="margin-left:30%;">

```mermaid
classDiagram
    SnakeGame <|-- Snake
    SnakeGame: main()
    Snake *-- Direction : Composition
    class Direction {
        <<enumeration>>
        STOP = 0
        UP
        RIGHT
        DOWN
        LEFT
    }
    class Snake{
        -int width
        -int height
        -int snakeX, snakeY
        -int fruitX, fruitY
        -int score
        -Direction dir
        -int tailX[ ], tailY[ ]
        -int nTail
        +bool gameOver
        +Snake()
        +~Snake()
        +Setup()
        +Draw()
        +Input()
        +Logic()
    }
```
</div>


<br/>
## Support

<a href="https://www.buymeacoffee.com/jordian" target="_blank" style="margin-left:50px;"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="180" style="border-radius:10px"></a>
