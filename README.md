# dislyte-sim
Dislyte Battle Simulator in C

## IN ALPHA ALPHA v0.0000001
Initial commit to have a base setup and see if I can figure out dislytes turn taking action points algorithm implementation.

Can currently feed a team in through text file, and calculate ap / take a turn.

Only supports Clara and Zeus at the moment.


## For Users 
Install the exe

Usage in command line/cmd with ```simlyte.exe txtfile.txt```, example txt file in repo.

Format is ```ESPER HP ATK DEF etc...``` where each stat is the purple +number in the esper select screen. Base stats already calculated.

## For Devs
Build with ninja

Add espers in characters.c using their base stats for each.
