# rsg: A Random String Generator Program
## Introduction
rsg(Random String Generator) is a tool programmed by AECC1234, which is used to generate multiple lines random string combined with lowercase letters, capital letters and numbers. This tool is running on Linux system.  
## Usage
The structure of this command are listed here:
```bash
rsg [-m] a/A/0/aA/a0/A0/aA0(Default)
    [-l] line
    [-c] words-count-each-line
    [-s] /path/to/your/file
    [-v] show the program version
    [-h] show the help info
```
## Parameters
`-m`: Choose which combination would you like, you need to provide a spicific generating mode. "a" means using lowercase letter only, "A" means using capital letters only, and "0" means use number only. And you can combine these characters such as "aA" (means use both lowercase letters and capital letters).   
`-l`: Providing a number larger than 1, it is used to decide how many lines you want to generate.  
`-c`: Max characters in each line.  
`-s`: Save the generation result as a file.  
`-v`: Show the version of this program.  
`-h`: Show the help informations.
  
Example:  
Generate the random strings with 3 types of characters, there have 100 lines will print on the screen, and each line has 50 characters.  
```bash
rsg -l 100 -c 50 -m aA0
```
## Installation
When you downloaded these folder from Github, you firstly start CLI on the folder path, and input following codes to compile this project.  
```bash
make
```  
Then input following command lines to install on your system.  
```bash
sudo make install
```  
If you want to remove the program, you just run this command on the folder path:  
```bash
sudo make remove
```
## Version History
- **v1.2.0** Added a function about helping manual, now you can input `rsg -h` to get for help. (Aug 21, 2025)  
- **v1.1.0** Added a function about version checking, now you can input `rsg -v` to check your program version. (Aug 20, 2025)  
	     Changed the logic of parameters checking.
- **v1.0.1** Fixed some bugs about saving as file, resolved the strange character on the end of each line. (Aug 19, 2025
)  
- **v1.0.0** The basic version of this program. (Aug 16, 2025)  
