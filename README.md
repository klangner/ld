# Line direction detector

This is a library based on [opencv](opencv.org) for finding line on the picture and estimating its direction. 
The goal of this project is to create library for the line following robot with camera as a main sensor.

## How does it work

* Acquire image from the camera

![Input](https://raw.github.com/klangner/ld/master/doc/source.png)

* Convert to binary image
* Draw circle and find all black pixels ont the circle
* The median pixel is our direction

![Input](https://raw.github.com/klangner/ld/master/doc/final.png)
