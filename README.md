# Line detector

This is a library based on [opencv](opencv.org) for finding line on the picture and estimating its direction. 
The goal of this project is to create library for the line following robot with camera as a main sensor.

## How does it work

* Aguire image from camera
* Convert to binary image
* Draw circle and find all black pixels
* The median pixel is our direction
