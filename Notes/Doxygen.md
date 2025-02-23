## Doxygen

#### What is code documentation?
the descriptive text to your codebase to explain the purpose, functionality, and architecture of the software


#### Benefits of code documentation
ensures that developers can understand , maintain, update code in easy way
also foster collaboration and knowledge shaing among team members



#### What is Doxygen
is a de facto standard tool for generating documentation from popular programming languages such as: C/C++, objective-C, C#, Python, Java, PHP, Fortran, VHDL


#### Doxygen output file types
can generate
HTML, LaTeX, hyberlinked Pdf, RTF(MS-word), unix man pages


#### Install doxygen, and graphviz as GUI
- install vscode extensions((Doxygen , Doxygen Documentation Generator)

### By terminal
sudo apt install doxygen

$ doxygen -g // for configuration
$ doxygen // generate doxygen output files

#### Documenting the code
There are serveral ways to mark a comment block as a detailed description:
- Javadoc style, which consist of a C-style comment block starting q=with **
```c
/**
* ...text...
*/
```
- Qt style
```c
/*!
* ...text...
*/
```
- intermediate *'s is optional
```c
/*!
  ...text...
*/
```
```c
///
/// ...text..
///
```

```c
//!
//! ...text..
//!
```

#### Putting documentation after members
members of a file like struct, union, class, or enum.
- sometimes desired to place the documentation block after the member instead of before, in this case, you have to add an additional < maker in the comment block

```c
int var; /**< Detailed description after the member */
```

```c
int var; /*!< Detailed description after the member */
```

### Doxygen Special Commands
All commands in the documentation starts with a backslash(\) or at-sign (@)
\a
\addindex


##### @mainpage [(title)]

#### \image <format> <file> ["caption]
["caption] is optional
```c
/**
* \image html application.jpg "My app"
```

#### \param <paramter-name> <file> {paramter description}

#### \return {description of the return value}

#### Doxygen Configuration file
Doxygen

### References
- [Doxygen for vscode, linux](https://www.youtube.com/watch?v=KiEBrykcHc4)
- [Doxygen-Mohamed Youssef](https://www.youtube.com/watch?v=FEL4C3XLJO4)
[graphviz](https://graphviz.org/download/)- 