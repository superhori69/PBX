# PinballRemasterX

## Summary

Reverse engineering of `Full Tilt - Space Cadet Level`.

## How to play

Place Lib and GameData into the folder containing source files (Included in my cdn).\
Supports data files extracted from Full Tilt pinball game.

## Libs + Game Data

| Platform           | Source          | URL                                                                                                        |
| ------------------ | --------------- | ---------------------------------------------------------------------------------------------------------- |
| Windows            | Xan CDN         | [Download GameData+Libs from here](https://cdn.xan-core.tk/pbx-requirements/GameData+Libs.7z)              |

Platforms covered by this project: Windows.

<br>

## Tools used

`Visual Studio 2022`

## What was done

* All structures were populated, globals and locals named.
* All subs were decompiled, C pseudo code was converted to compilable C++. Loose (namespace?) subs were assigned to classes.
* Better and more optimized game engine.

## Compiling

Project uses `C++11` and depends on `SDL2` libs.

### On Windows

Download and unpack [GameData+Libs.7z](https://cdn.xan-core.tk/pbx-requirements/GameData+Libs.7z) archive into the source folder.\
The `Lib` folder does not need to be renamed.\
Compile with Visual Studio. Tested with Visual Studio 2022.
