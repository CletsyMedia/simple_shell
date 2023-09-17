# Ink and Embers: ALX's Collaborative Dance of Unix-Shell

![Simple Shell Logo](https://dinahosting.com/blog/upload/2021/05/Que-es-Bash-Script.jpg)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Commands](#commands)
- [Contributors](#contributors)
- [Limitation](#limitations)
- [Support](#support)
- [Contact](#contact)

## Introduction

Welcome to our Simple Shell project, where code and dreams converge! Within this realm of hallowed scriptorium, we unveil a command-line interpreter, a humble oracle, granting you access to the soul of your computer's operating symphony.

Our Simple Shell, like a muse from Unix's ethereal tapestry, gracefully mirrors the grandeur of its Bash brethren, yet dances with the grace of simplicity, offering a serene haven for seekers of the elemental.

This collaborative odyssey unfolds, forging a path towards a user-friendly, Unix-like sanctuary, where the essence of command-line artistry thrives. We embark on a quest to illuminate the secrets of shell symphonies, to be the guiding light for fledgling minds.

So, dear kindred spirits, heed the call and join us in this eloquent creation, where function meets instruction, and together, we craft a sonnet of command-line mastery. In our Simple Shell, let code and camaraderie unite us in the tapestry of Unix dreams.

## Features

- An interactive command-line interface, where keystrokes become notes in the shell's timeless melody.

- Support for invoking external commands, where binaries and scripts sing in harmony with built-in shell commands.

- A canvas for the art of environment variable manipulation, where settings and values form the palette of your digital masterpiece.

- The crafting of aliases, ephemeral yet powerful, allowing you to name your commands in the tongue of your heart's desire.

- Command execution, an intricate dance of semicolons and logical operators, a choreography of control and precision.

- The graceful handling of exit statuses, where each command's finale is met with the applause of success or the solace of failure.

- The conjuring of files and directories, creation and deletion, like sorcery, bending the digital realm of shell to your will.

## Installation

In the realm of our Shell, where code whispers secrets, installation unfolds thus;

- Clone our digital manuscript, a repository, like pages of an ancient scroll.

```sh
git clone https://github.com/CletsyMedia/simple_shell.git
```

## Compilation

- To weave this symphony, with lines of code we cast and compile with precision using this spells:

```sh
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage

- Now, the stage is set, and the spotlight beckons, invoke the Simple Shell, breathe life into the script, with the command:

```sh
./hsh
```

## Commands

As the shell awakens, you can begin your voyage, weaving commands and exploring its array of functions. The Simple Shell welcomes a spectrum of commands and features like:

- External commands (ls, cd, touch, mkdir) are like stardust in the night sky.
- Built-in commands (exit, env, setenv, unsetenv, alias) are secrets of the shell's heart.
- Manipulate the environment (export, import, unset), like an artist with a palette.
- Craft and conjure aliases, like incantations whispered.
- Command execution, a dance of logic AND(&&) and logic OR(||) operators.
- Handling exit status, an epilogue to each act.

Upon entering the realm of the Simple Shell, you possess the power to invoke command prompts, much akin to the familiar landscape of a standard shell. Here, a handful of illustrative examples:

```sh
$ ls -l
$ touch Hello, Simple Shell!
$ exit
$ mkdir
$ ls -la
```

- To view the current environment variables, you can use the `env` command:

```sh
$ env
```

- Use semicolons to separate multiple commands on a single line:

```sh
$ ls -l ; mkdir new_directory ; touch file.txt
```

- Manipulate environment variables using the export, unset, and echo commands:

```sh
$ export MY_VARIABLE="Hello, Simple_Shell!"
$ echo $MY_VARIABLE
$ unset MY_VARIABLE
```

- Working with aliases to create shortcuts for frequently used commands:

```sh
$ alias bk="cd .."
$ alias
```

- Navigate directories with the cd command:

```sh
$ cd path/to/directory
```

- Execute built-in commands like exit, env, setenv, unsetenv, and alias:

```sh
$ exit
$ env
$ setenv VAR_NAME VAR_VALUE
$ unsetenv VAR_NAME
$ alias bk="cd .."
```

## Contributors

This scriptorium of shell is a collaborative effort by [Cletus Samuel](https://github.com/CletsyMedia) and [Amanda Obi](https://github.com/ObiChika).

## Limitations

In the grand design of Simple Shell's dream, where command-line echoes gleam, amidst its grace behold uncertainties surrounds it scene:

1. **Limited Feature Set:** The Simple Shell may not offer the extensive feature set of more mature shells like Bash. Advanced or niche functionalities might be missing.

2. **Error Handling:** Error handling in the shell might not be as comprehensive as established shells, which could lead to unexpected behavior or error messages.

3. **Compatibility:** The shell might not be compatible with all systems or platforms, potentially resulting in compatibility issues on certain operating systems.

4. **Performance:** Due to its minimalist design, certain operations within the shell might exhibit slower performance compared to optimized shells.

5. **Bugs and Incompleteness:** The shell might have unresolved bugs or areas where certain features are incomplete. Users should be aware that it's an ALX educational project.

For every constraint we face, a chance to rise and soar, in the hands of fellow dreamers, we seek to explore. As the project evolves we welcome contributions from fellow voyagers to address these limitations.

## Support

If the Simple Shell's embrace beckons you near, follow these steps, there's no need to fear. Together we'll journey, in this collaborative art:

1. **Fork the Repository:** Start by forking the [Simple Shell repository](https://github.com/CletsyMedia/simple_shell) to your own GitHub account.

2. **Clone the Fork:** Clone your forked repository to your local machine using the following command:

```sh
git clone https://github.com/CletsyMedia/simple_shell.git
```

3. **Create a Branch:** Create a new branch for your feature or bug fix:

```sh
git checkout -b feature/your-feature-name
```

4. **Make Changes:** Make your improvements, fixes, or additions to the codebase.

5. **Commit Changes:** Commit your changes with descriptive commit messages: 

```sh
git commit -m "Add your commit message here"
```

6. **Push to Your Fork:** Push your changes to your forked repository.

7. **Create a Pull Request:** Go to the Simple Shell repository on GitHub and create a pull request from your forked repository's branch to our main branch. Provide a clear description of the changes you made. We will review your contribution and provide feedback. Thank you for helping make Simple Shell better!

## Contact

For queries, echoes, and thoughts that bloom and fuss, don't hesitate to connect, in our haven. [Cletus Samuel](https://cletsymedia.github.io/Prof-Portfolio/) and [Amanda Obi](https://github.com/ObiChika)🙏🙏🙏🙏🙏🙏🙏
