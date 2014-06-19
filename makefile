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

.PHONY: all clean install uninstall dirs testmake debug
CXX=g++
CXXFLAGS=-Wall -fexceptions -O2
DBFLAGS= -DDEBUG=1 -W  -g

PROG := ccat
PROG_REL := bin/$(PROG)

SRCFILES := $(wildcard src/core/*.cpp src/*.cpp)
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCFILES))
OBJS_DEBUG := $(patsubst src/%.cpp,obj/debug/%.o,$(SRCFILES))
OUTDIRS= ./bin ./obj ./obj/core ./obj/debug ./obj/debug/core

all: clean dirs  $(OBJS)
	@echo "----  Compilling...  ----"
	$(CXX) $(CXXFLAGS) -o $(PROG_REL) $(OBJS) 

dirs:
	@mkdir -p $(OUTDIRS)
	
clean:
	@rm -rf $(OUTDIRS)

install:
	@echo "----  Installing...  ----"
	install -g root -o root -m 755 $(PROG_REL)  /usr/bin/$(PROG)

uninstall:
	@echo "----  Uninstalling...  ----"
	rm /usr/$(PROG_REL)

testmake:
	@echo "----  Testmake...  ----"
	@echo $(SRCFILES)
	@echo $(OBJSY)
	@echo $(CXXFLAGS)

debug: clean dirs $(OBJS_DEBUG)
	@echo "----  Compilling debug binary...  ----"
	$(CXX) $(DBFLAGS) -o $(PROG_REL) $(OBJS_DEBUG) 

obj/core/%.o: src/core/%.cpp
	$(CXX)  $(CXXFLAGS) -c $< -o $@

obj/%.o: src/%.cpp
	$(CXX)  $(CXXFLAGS)  -c $< -o $@


obj/debug/%.o: src/%.cpp
	$(CC) $(DBFLAGS) $(CFLAGS)  -c $< -o $@
