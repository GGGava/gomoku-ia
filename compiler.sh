#!/bin/bash
g++ -o gomoku Game.cpp GUI.cpp gomoku.cpp IA.cpp Element.cpp Graph.cpp -std=c++11 -Ofast -w
