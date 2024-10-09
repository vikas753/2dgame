Prereq : 
brew install glfw3

Simple Commandline to compile main.cpp file is as below

g++ main.cpp glad/src/glad.c -I$(brew --prefix)/include -L$(brew --prefix)/lib -lglfw  -I../glfw/include -Iglad/include -framework OpenGL
g++ main.cpp -I$(brew --prefix)/include -L$(brew --prefix)/lib -lglfw  -I../glfw/include -Iglad/include -framework OpenGL
# 2dgame
