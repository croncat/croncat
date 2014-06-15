#
# makefile
# Copyright (C) 2014 Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
#
# croncat is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# croncat is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.
#

# this makefile need refactoring!

all:
	mkdir ./bin
	mkdir ./obj
	mkdir ./obj/core
	g++ -Wall -fexceptions -g -c ./src/core/alarm_clock.cpp -o ./obj/core/alarm_clock.o
	g++ -Wall -fexceptions -g -c ./src/core/service_mode.cpp -o ./obj/core/service_mode.o
	g++ -Wall -fexceptions -g -c ./src/core/timer.cpp -o ./obj/core/timer.o
	g++ -Wall -fexceptions -g -c ./src/main.cpp -o ./obj/main.o
	g++  -o ./bin/ccat ./obj/core/alarm_clock.o ./obj/core/service_mode.o ./obj/core/timer.o ./obj/main.o
	
clean:
	rm -r ./bin
	rm -r ./obj

install:
	cp -p ./bin/ccat /usr/bin/ccat
	chown root /usr/bin/ccat
	chgrp root /usr/bin/ccat
