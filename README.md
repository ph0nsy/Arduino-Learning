# Arduino Learning

This repository is where I experiment with Arduino, learning the fundamentals of working with hardware and build things to understand how they work in practice.
I'm using Git history to document the process, so jump to any of the documented commits (or a random one, whatever floats your boat) to check how it was implemented.

[_Explore the commit history_](https://github.com/ph0nsy/Arduino-Learning/commits/main)

_[Go to `main` Branch](https://github.com/ph0nsy/Arduino-Learning/tree/main)_

## 1. Binary counter

_[View Commit](https://github.com/ph0nsy/Arduino-Learning/tree/c3ec58170c44292dec32c15b78eebdbdbf204bd0)_

## 2. Potentiometers - Dimmable LED

_[View `potentiometer` Branch](https://github.com/ph0nsy/Arduino-Learning/tree/potentiometer)_

### 2.1. Summary

Find the relationship between potentiometer value (0-1023) and LED value (0-255) to create a dimmable LED according to the potentiometer state (255/1023).

### 2.2 Implementation

||
|:---:|
|![Potentiometer](assets/potentiometer_diagram.png)|
| Potentiometer inner workings diagram. | 

|||
|:---:|:---:|
|![Board_1](assets/board_picture_02_1.png)|![Board_2](assets/board_picture_02_2.jpg)|
| Arduino board circuit connections. | Real life circuit. | 

> 📑 **Note**
>
> While following Paul McWhorter's tutorials, I realized that my Arduino Kit didn't include a potentiometer — unlike his — so I had to buy one. The only affordable one I was able to find (courtesy of [Conectrol](https://conectrol.com/)) was a bit different than the one in the tutorials.
> This doesn't make anything different — neither for implementation nor for circuit design — but it may be confusing at first so, just in case you are in a similar situation:
> ![Potentiometers](assets/Potentiometers.png)

### 2.3. Learnt on this section

||
|:---:|
|![Slope](assets/potentiometer_slope_diagram.png)|
| Slope for potentiometer values. | 

## Special Thanks

- Paul McWhorter's [_New Arduino Tutorials_](https://www.youtube.com/playlist?list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP) YouTube series.
