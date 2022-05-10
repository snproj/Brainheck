# Brainheck
A fun little way to "encrypt" and "decrypt" text, inspired by a trivial use case of the well-known esolang Brainfuck. Hence the "milder" Brain*heck*.

## The three parts
### Main
This is actually the least relevant file and is more or less just me trying to create a Brainfuck environment using C macros. Ignore it.

### MainEncoder
Compile and run with the text to be encoded as an argument. It'll output an `output_file.txt` with the corresponding Brainheck. There's sometimes an issue where the output is all unreadable characters; I wrote this when I was unfamiliar with programming and never really got around to fixing it haha. Maybe one of these days!

### MainDecoder
Compile and run, then follow the prompt to enter the filename of the Brainheck to be decoded.

## How it works
Basically, we can imagine a register containing an integer value initialized at zero. To print 'A', we increment that value to 65 (ASCII value) and output one character. To print 'B', we add 1 to that register (remember that register is already at the ASCII code for 'A') and hit output again.

Using this very simple procedure, we can convert "ABED" to
- start at 0
- increment 65 times
- output
- increment 1 time
- output
- increment 3 times
- output
- decrement 1 time
- output

Let's assign `p` to increment, `m` to decrement and `o` to output; this becomes:
```
pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppopopppomo
```
You can imagine this becomes pretty long for long texts.

## Purpose
This is a very simple procedure that I tend to use as my "hello world" for various languages and technologies. This was my first implementation of it, a few months after starting to touch programming!