# Launcheroo

[![License MIT](https://cdn.rawgit.com/pkoretic/letihome/badges/license.svg)](https://github.com/pkoretic/letihome/blob/master/LICENSE)
[![Language (Qt)](https://cdn.rawgit.com/pkoretic/letihome/badges/qt.svg)](https://www.qt.io)

Linux launcher optimized for the big screen. Targets embedded and TV/STB devices. It is intended
to be very performant, correct and simple minimizing memory usage.

![LetiHome Screenshot](https://raw.githubusercontent.com/pkoretic/LetiHome/badges/screenshot.jpg)

## Building

It is written using Qt/QML and requires Qt 5.9, although it will run fine with 5.7 or older if
module versions are lowered in `main.qml`.

It is a regular Qt android application. For more info see
http://doc.qt.io/qt-5/android-support.html.

Open `CMakeLists.txt` in QtCreator and your are good to go.

## Usage

Keys or mouse can be used to open applications.<br/>
Navigational keys are used to move through application list and `Enter/Return (OK on remotes)` are
used to open currently selected application.<br/>
`Menu` key or mouse `right click` can be used to open wallpaper picker.<br/>
Mouse `left click` also opens application.

## Support

Launcher can be easily extended to support many different scenarios. I am aiming to use it as a simple Linux launcher for TV boxes.
