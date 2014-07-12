croncat
=======

#### croncat: The Portable and Lightweight Time Manager! 

Croncat is a command line program; is very useful for usage with commands and scripts. We need your help for testing/hacking/developing. The project is in initial times!

Croncat intended as a portable utility (with versions for all operating systems, including Windows and Mac) for fast prototyping of control systems and time management, without requirements of specific os tools, such as crond (linux-bsd) or schtasks (win).


## Getting the source

You can either download the source using the "ZIP" button at the top
of the github page, or you can make a clone using git:

```
git clone https://github.com/croncat/croncat.git
```


## Install

```
$ make
# make install
```


## Usage

For help, type 'ccat' in your terminal.

```
$ ccat
croncat 0.2a ( http://github.com/croncat )
Usage: ccat [OPTION] {ARGUMENT/S} "COMMAND"
OPTIONS:
  -d: time and date (format HOUR MINUTES SECONDS DAY MONTH YEAR DST)
  -i: interval time (format CYCLES TIME UNIT[ms, s, m, h, d])
  -l: left time (format TIME UNIT[ms, s, m, h, d])
EXAMPLES:
  ccat -d 15 53 30 22 03 2013 0 "gxmessage hello"
  ccat -i 3 4000 ms "gxmessage hello"
  ccat -i 5 45 m "gxmessage hello"
  ccat -l 30 s "gxmessage hello"
  ccat -l 1 h "gxmessage hello"
croncat: The Portable and Lightweight Time Manager!
```


## Team

The croncat project is open source and maintained by a team of volunteers.
You can join the [team on Google Groups](https://groups.google.com/forum/?fromgroups#!forum/croncat).


## Downloads!

croncat download on [k0ch's homepage](http://koch.bshellz.net/downloads.html).
