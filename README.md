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
```
## Parameters
`-m`: Choose which combination would you like, you need to provide a spicific generating mode. "a" means using lowercase letter only, "A" means using capital letters only, and "0" means use number only. And you can combine these characters such as "aA" (means use both lowercase letters and capital letters).   
`-l`: Providing a number larger than 1, it is used to decide how many lines you want to generate.  
`-c`: Max characters in each line.  
`-s`: Save the generation result as a file.  
## Installation
When you downloaded these folder from Github, you firstly start CLI on the folder path, and input following codes to compile this project.  
```bash
make
```  
Then input following command lines to install on your system.  
```bash
sudo make install
```
