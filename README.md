# **Game of Life**
## Authors

 - [Marco Antonio](github.com/MarcoAFC)
 - [Leonardo Nammur](github.com/Nammur)
## About the project

  This is an exercise project made for the course DIM0120 and has the objective of implent a [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) generator. The game of life is a cellular automaton in which, given a initial setting for the system, several "alive" cells are placed in the board, and the remaining space of the board is filled with dead cells the board's content is iterated according to a given set of rules, through which any given cell can remain alive, die, or be born if certain criteria are met. The classic rules are:
    - Any live cell with fewer than 2 neighbours dies of solitude.
    - Any live cell with two or three live neighbours stays alive.
    - Any live cell with more than three live neighbours suffocates and dies.
    - Any dead cell with 3 neighbours is set alive due to reproduction.

  Other sets of rules are possible, but must be user-inputed, if they are neccessary.
  The game is set to run until one of three conditions is met:
    - A configuration has repeated itself.
    - All cells are dead.
    - User-inputed maximum number of iterations has been reached.
   
## Usage
  ##TODO
  To download and use this program, please clone the repository to your environment, then open the terminal in the corresponding file and use the command **Make**.\
  Afterwards bash the executable file with **./life** [<*options*>] --path **<input_file>**, where:\
    **Facultative parameters:**\
      - --help:\
        Prints a text detailing the options possible for usage.\
      - --imdgir:\
       Allows the user to set the directory where the image output is printed.\
      - --maxgen:\
        Allows the user to set a maximum limit to the ammount of iterations that should be played.\
      - --fps:\
        Allows the user to set the number of generations printed to the terminal every second. Can
        be used to allow better visualisation of the progress.\
      - --bkgcolor:\
        Allows the user to set the Color used in the background, I.E. dead cells.\
        If none given, defaults to green.\
        Available colors are:\
        green, red black, crimsom, dark_green, deep_sky_blue, dodger_blue, light_blue, light_grey,\light_yellow, steel_blue, yellow and white.\
      - --alivecolor:\
        Allows the user to set the Color used for live cells. The colors available are the sames of the previous text.\
        If none given, defaults to red.\
      - --blocksize:\
        Allows the user to set the size of a pixel block representing a cell. Defaults tp 5x5 pixel blocks.\
      - --outfile:\
        Allows the user to print the terminal output to a file, whose name should be placed after this tag.\
    **Required parameter:**\
       - --path input_file\
        The user must input the path to a initial configuration file in the format specified in the next session.\
    **Example:**\
        An example call for the program would be:
        ./a.out --path ../input/input.txt --imgdir ../data/ --blocksize 20\   
