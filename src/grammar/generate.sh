#!/bin/bash
antlr4 -Dlanguage=Cpp -visitor -o ../generated/ Avrlang.g4
