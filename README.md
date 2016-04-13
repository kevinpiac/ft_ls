# FT_LS 
The project goal is to recode the LS function present in unix system using C programming language.

## Available options:

- -l -> show in list format + informations about rights & more...
- -R -> recursive search as explaine below
- -a -> showing all, even where name begins by '.' or '..'
- -r -> reverse the listing order
- -t -> order by date (more recent first)

Other option (bonus):

- -u
- -f
- -g
- -d


## PERSONAL MEMO.
### 1. ls (with or whitout -l option) reorganizes each dir/file lexicagraphically

``` sh
-- touch a b c 1 && ls
1 a b c
```
``` sh
-- touch b c a && ls
a b c
-- ls -l
-rw-r--r--  1 kpiacent  2015_paris  0 Apr 13 09:44 a
-rw-r--r--  1 kpiacent  2015_paris  0 Apr 13 09:43 c
```
``` sh
-- mkdir a1 a0 b1 b2 c1 c2 && ls
a  a0	 b	b1   b2 c	 c1	c2
```
### 2. ls -R displays the content of each directory recursivelly
Note: if directory is empty a \n is displayed.

``` sh
-- mkdir a b c 1
-- mkdir a/aINa
-- touch 2 a/fileINa a/aINa/fileINaINa b/fileINb
-- ls -lR
./1:

./a:
aINa		fileINa

./a/aina:
fileINaINa

./b:
fileINb

./c:
e3r1p12% ls -lR
total 32
drwxr-xr-x  2 kpiacent  2015_paris  4096 Apr 13 09:49 1
drwxr-xr-x  3 kpiacent  2015_paris  4096 Apr 13 09:51 a
drwxr-xr-x  2 kpiacent  2015_paris  4096 Apr 13 09:51 b
drwxr-xr-x  2 kpiacent  2015_paris  4096 Apr 13 09:49 c
```


PARCOUR ORDER :

- list all files / dirs in current dir
- list all files / dirs in each directory
- list all files / dirs in directories of directories
``` sh
Assuming 1 and 2 are both directories

1/
files in 1
dir in 1

dir in 1/
files in "dir in 1"
dir in "dir in 1"

dir in "dir in 1"
files ......
dir......

2/
files in 2
dir in 2

etc.
```