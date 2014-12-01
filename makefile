# Copyright (c) 2014, 
# Emiliano Gabriel Canedo <emilianocanedo@gmail.com>
# Facundo Acevedo <acv2facundo@gmail.com>
# 
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# * Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
# 
# * Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
# 
# * Neither the name of croncat nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

.PHONY: all clean install uninstall dirs testmake debug
CXX=g++
CXXFLAGS= -Wall -fexceptions -O2
DBFLAGS= -DDEBUG=1 -W  -g

PROG := ccat
PROG_REL := bin/$(PROG)

SRCFILES := $(wildcard src/core/*.cpp src/*.cpp)
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCFILES))
OBJS_DEBUG := $(patsubst src/%.cpp,obj/debug/%.o,$(SRCFILES))
OUTDIRS= ./bin ./obj ./obj/core ./obj/debug ./obj/debug/core

all:	clean dirs $(OBJS) 
	@echo "---- Building... ----"
	$(CXX) $(CXXFLAGS) -o $(PROG_REL) $(OBJS) 
	@echo "---- Done! now run 'make install' as root ----"	

dirs:
	@mkdir -p $(OUTDIRS)
	
clean:
	@rm -rf $(OUTDIRS)

install:
	@echo "---- Installing... ----"
	install -g root -o root -m 755 $(PROG_REL)  /usr/bin/$(PROG)
	@echo "---- Done! ----"

uninstall:
	@echo "---- Uninstalling... ----"
	rm /usr/$(PROG_REL)
	@echo "---- Done! ----"

testmake:
	@echo "Compiler: "$(CXX)
	@echo "Compilation flags: "$(CXXFLAGS)
	@echo "Debug flags: "$(DBFLAGS)
	@echo "Source files: "$(SRCFILES)
	@echo "Object files: "$(OBJS)
	@echo "Directories: "$(OUTDIRS)

debug: 	clean dirs $(OBJS_DEBUG)
	$(CXX) $(DBFLAGS) -o $(PROG_REL) $(OBJS_DEBUG) 

obj/core/%.o: src/core/%.cpp
	$(CXX)  $(CXXFLAGS) -c $< -o $@

obj/%.o: src/%.cpp
	$(CXX)  $(CXXFLAGS)  -c $< -o $@

obj/debug/%.o: src/%.cpp
	$(CC) $(DBFLAGS) $(CFLAGS)  -c $< -o $@
