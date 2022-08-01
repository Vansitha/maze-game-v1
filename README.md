## Program Overview
- The program is an implementation of a classic maze game where the player must navigate the map to reach the goal. 
- Users can interact with the player character using 'w', 'a', 's' and 'd' keys to navigate the maze to the goal. 
- The program is launched with the default settings, allowing the user to view the whole map. 
- To make the game more challenging, the visibility distance can be adjusted so that the player has restricted vision 
  of the map while moving across it to reach the goal. 
- With visibility set, various areas of the map around the player will be revealed as the player advances.

## How to run the program
- Step1: Run `make` command
- Step2: Run `./maze`

## Running with conditional compilation to set visibility distance (optional)
Step1: Run `make DARK=1` 
Step2: Run `./maze 2` (Number represents the visibility area)

## Details to note
1. IF DARK=1 is activated during compilation and user fails to set visibility distance, program 
          runs with default visibility setting which is set to display enitre map.
2. If user passes a negative value or 0 as an argument, program runs with default visibility setting.
