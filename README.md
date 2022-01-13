## What is it?

This is bindings for the [WebAssembly](https://webassembly.org/) of the [RVO2 library](https://gamma.cs.unc.edu/RVO2/). It use [Emscripten](https://emscripten.org/) as compiler.

## How to build

Step 1. Compile all *.cpp files in the ```rvo_src``` directory into *.o file. Simply call for each *.cpp file the following command

```
emcc rvo_src/RVOSimulator.cpp -o rvo_src/RVOSimulator.o -c
```

Step 2. Compile output *.wasm module. The main file is ```rvo.cpp``` It contains all bindings for c++ objects. Also you need to link *.o files to the compiler and use ```--bind``` key. So, the example of the build command is the following:

```
emcc rvo.cpp rvo_src/Agent.o rvo_src/KdTree.o rvo_src/Obstacle.o rvo_src/RVOSimulator.o -o output/rvo.js --bind -s MODULARIZE -s EXPORT_NAME=RVO -s ALLOW_MEMORY_GROWTH=1 -I rvo_src
```

To build compressed optimized module use the key ```-Oz```