# CPE 2022 - Corewar

## Project
[](https://github.com/NolannB14/Corewar/blob/main/assets/corewar_example.gif)
* [Corewar](https://en.wikipedia.org/wiki/Core_War) is a game. A very special game. It consists of pitting little programs against one another in a virtual machine.<br>
The goal of the game is to prevent the other programs from functioning correctly by using all available means.<br>
The game will, therefore, create a virtual machine in which the programs (written by the players) will face off. Each program’s objective is to “survive”, that is to say executing a special instruction ("live") that means I’m still alive. These programs simultaneously execute in the virtual machine and in the same memory zone, which enables them to write on one another.<br>
The winner of the game is the last one to have executed the "live" instruction.
* We have to separate the project into 3 parts:
    * asm: compile [redcode](https://en.wikipedia.org/wiki/Core_War#Redcode)
    * vm (virtual machine): interpret the binary produced by the asm part to launch the `champions` in an virtual arena
    * champions: your handiwork: composed of redcode, they must be able to fight and leave the machine arena <br><br>

### How to use the project
---
* Clone the project
```
git clone git@github.com:NolannB14/Corewar.git Corewar
```
* Go into the folder (`cd Corewar`)
* Compile the project
```
make ; make clean
```
* Launch each part

### Asm part
At the root of the repository:
```
./asm/asm [file to be compiled] [-h]
```
* The file must be a `.s` file, and be composed of redcode
* `-h` to display infos about program.

### Corewar part
At the root of the repository:
```
./corewar/corewar [.cor file] [-h] [options]
```
* The file must be a `.cor` file, and a binary file
* `-h` to display infos about program.
* the followings options are possible:
```
-dump: (nbr_cycle) dumps the memory after the nbr_cycle execution (if the round isn’t already over) with the following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)
-n: (prog_number) sets the next program’s number. By default, the first free number in the parameter order
-a: (load_address) sets the next program’s loading address. When no address is specified, optimize the addresses so that the processes are as far away from each other as possible. The addresses are MEM_SIZE (6*1024) modulo.
```

## Redcode
Here is a list of all the instructions, and the parameters taken
[](https://github.com/NolannB14/Corewar/blob/main/assets/instructions.png)

# How to contribute to the project
Here is the official Epitech pdf on the subject [](https://github.com/NolannB14/Corewar/blob/main/assets/infos.pdf)<br>
And the Coding style to follow [](https://github.com/NolannB14/Corewar/blob/main/assets/epitech_c_coding_style.pdf)
* N.B: the project is finished since 22/05/2022, 23h42

## Authors
    * Luka Camus
    * Samuel Florentin
    * Louis Bassagal
    * Nolann Bougrainville
