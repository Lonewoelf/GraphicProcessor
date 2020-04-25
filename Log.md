<h1> GraphicProcessor Progress Log </h1>

This log descibes the process of how the final product for the individual project course at Avans Hogeschool was made.
At the start I'll take a look at what idea's I have for this project, this will influence the choice between OpenGL and OpenCL. <br>
After that I will do more research on the prefered API, and then I will formulate the definitive goal for this project.<br>
At the end the entire development process from start to finish will be described.

<h2> Table of Contents </h2>

1. [OpenGL or OpenCL?](#GLCL)
3. [Information on OpenGL ](#GL)
4. [Goal](#Goal)
5. [Path to Goal ](#PtG)

<a name="GLCL"></a>
## OpenGL or OpenCL?

Upon googling the differences between those two environments, <br>
one of the first things that pops up is the following: <br>

OpenGL is mostly used for computer graphics, it is a graphics API. <br>
OpenCL is mostly used for parallel computing, it is a computation API. <br>

Since I prefer to produce something visual rather than just performing calculations.
It would also be nice to create something that I could use to make my room look nicer.
An added bonus is that there seem to be more examples for OpenGL than for OpenCL.

<a name="GL"></a>
## Information on OpenGL

Sources: <br>
https://en.wikipedia.org/wiki/OpenGL <br>
https://learnopengl.com/Getting-started/OpenGL <br>
https://www.khronos.org/opengl/wiki/Getting_Started#Downloading_OpenGL <br>
https://www.absingh.com/opengl/

Fun Examples: <br>

1. Terrain generation: https://www.codeproject.com/Articles/14154/OpenGL-Terrain-Generation-An-Introduction <br>

Example terrain: <br>
![Simple terrain](/Images/SimpleTerrain.jpg)

2. 3D Water: https://www.youtube.com/watch?v=HusvGeEDU_U&list=PLRIWtICgwaX23jiqVByUs0bqhnalNTNZh <br>


<a name="Goal"></a>
## Goal

Maybe creating a water pool with some terrain around it? possibly with user interaction, maybe flying through the created terrain?

<a name="PtG"></a>
## Path to Goal

[25-04-2020]
Started following the 3D water turtorial in OpenGL, mentioned in point 2 of Fun Examples.
