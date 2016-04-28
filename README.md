# FT_LS
The project goal is to recode the LS function present in unix system using C programming language.

## Allowed functions:

- write
- opendir
- readdir
- closedir
- stat
- lstat
- getpwuid
- getgrgid
- listxattr
- getxattr
- time
- ctime
- readlink
- malloc
- free
- perror
- strerror
- exit

## Available options:

- -l -> show in list format + informations about rights & more...
- -R -> recursive search as explaine below
- -a -> showing all, even where name begins by '.' or '..'
- -r -> reverse the listing order
- -t -> order by date of last modification (more recent first)

(bonus):

- -u
- -f
- -g
- -d


## PERSONAL MEMO.
### 1. ls (with or whitout -l option) reorganizes each dir/file lexicagraphically

``` shell
-- touch a b c 1 && ls
1 a b c
```
``` shell
-- touch b c a && ls
a b c
-- ls -l
-rw-r--r--  1 kpiacent  2015_paris  0 Apr 13 09:44 a
-rw-r--r--  1 kpiacent  2015_paris  0 Apr 13 09:43 c
```
``` shell
-- mkdir a1 a0 b1 b2 c1 c2 && ls
a  a0	 b	b1   b2 c	 c1	c2
```
### 2. ls -R displays the content of each directory recursivelly
Note: if directory is empty a \n is displayed.

``` shell
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
``` shell
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

### 3. (stat) how to get informations about a file

    The buf argument is a pointer to a stat structure as defined by <sys/stat.h> and into which information is placed concerning the file.  When the macro _DARWIN_FEATURE_64_BIT_INODE is not defined (see below for more information about this
     macro), the stat structure is defined as:
``` shell
struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is NOT defined */
     dev_t    st_dev;    /* device inode resides on */
     ino_t    st_ino;    /* inode's number */
     mode_t   st_mode;   /* inode protection mode */
     nlink_t  st_nlink;  /* number of hard links to the file */
     uid_t    st_uid;    /* user-id of owner */
     gid_t    st_gid;    /* group-id of owner */
     dev_t    st_rdev;   /* device type, for special file inode */
     struct timespec st_atimespec;  /* time of last access */
     struct timespec st_mtimespec;  /* time of last data modification */
     struct timespec st_ctimespec;  /* time of last file status change */
     off_t    st_size;   /* file size, in bytes */
     quad_t   st_blocks; /* blocks allocated for file */
     u_long   st_blksize;/* optimal file sys I/O ops blocksize */
     u_long   st_flags;  /* user defined flags for file */
     u_long   st_gen;    /* file generation number */
 };
 ```

### 4. Process to store passed options

-> when an option is passed as param, ls function will raise a flag using bitwise in an unsigned int. Ex:
``` shell
    unsigned int i = 0;
    bit value : 0000 0000 0000 0000 0000 0000 0000 0000
    considering supported options : d,g,f,u,t,r,a,R,l
    all flags raised, bit value:

    options:                    d gfut raRl
    0000 0000 0000 0000 0000 0001 1111 1111
    index:                      8 7654 3210
```

### 5. How to store directory's content data

Each file contained in a directory is stored in a vector following the process below:

``` c
t_vector *v;

v = ft_vectnew();
dir_storecontent(path, v);

then we got:
v->total // amount of stored files (including . and ..)
v->items[i] // contain the file content at index i

```

The item is stored in a structure typedefed as t_filedata;

``` c
typedef struct		s_filedata
{
    char			*basepath; //the relative path to the parent dir of file
	char			*filename; //name of file
	char			*path;     //the relative path to the file (basepath + / + filename);
}                  t_filedata;

```

``` shell
    in case of -R (recursive)
    DIR1 <---------------------------------------------------------------------------------
    |___ DIR1 : *begin_list -> DIR2 -> *nextfile ... end.                                  |
                                |__ DIR2 : *begin_list -> *next file -> *nextdir... end ---

    otherwise
    DIR1
    |___ DIR 1: *begin_list -> nextfile -> nextfile ->nextdir... end.
```

#### Needed behaviours / functions
- reorganize linked list by modification time when adding a node
- read (or revert) a linked list
- be able to call recursively the function itself (if -R option)
- be able to find needed data (for -l)

#### Errors handling
- no rights on file or dir
- no file or dir

To be continued...

