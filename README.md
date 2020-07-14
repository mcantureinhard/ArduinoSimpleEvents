# ArduinoSimpleEvents

## About

Simple publish/subscribe library functions can be subscribed to topics and will be called whenever data is published to theirs. 

## Overview

Class is instantiated with the number of topics. Functions can be subscribed to these. When a publish happens, data is passed using a generic pointer and needs to be cast to the appropriate type in the subscribing functions. This allows to have different data types passed for different topics. 

## How to use

Clone this repository into your Arduino/libraries directory

## Example

See test.cpp file