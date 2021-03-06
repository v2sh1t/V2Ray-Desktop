# V2Ray Desktop

[![Build Status](https://travis-ci.org/Dr-Incognito/V2Ray-Desktop.svg?branch=master)](https://travis-ci.org/Dr-Incognito/V2Ray-Desktop)
[![Build status](https://ci.appveyor.com/api/projects/status/0t07jpv22tf7xpn9?svg=true)](https://ci.appveyor.com/project/Dr-Incognito/V2Ray-Desktop)
[![LGTM grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Dr-Incognito/V2Ray-Desktop.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Dr-Incognito/V2Ray-Desktop/context:cpp)
[![LGTM alerts](https://img.shields.io/lgtm/alerts/g/Dr-Incognito/V2Ray-Desktop.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Dr-Incognito/V2Ray-Desktop/alerts/)

## Introduction

V2Ray Desktop is a GUI client for [V2Ray](http://v2ray.com/), running on Windows, Linux, and macOS.
It is built with Qt 5 and QML 2.

Compared to [V2Ray](http://v2ray.com/), V2Ray Desktop provides more advanced features such as server subscription and latency test. You can easily migrate to V2Ray Desktop from [Shadowsocks-Qt5](https://github.com/shadowsocks/shadowsocks-qt5/) and [V2Ray Core](http://v2ray.com/) by importing their config files.

You can get the latest release at [Releases Page](https://github.com/Dr-Incognito/V2Ray-Desktop/releases). If you are using Arch Linux, you can install it from [AUR](https://aur.archlinux.org/packages/v2ray-desktop/).

For more information, please visit the [project's Wiki page](https://github.com/Dr-Incognito/V2Ray-Desktop/wiki).

**Note:** The AppImage for Linux is built in Ubuntu 16.04.5. Linux with GLIBC (Version < 2.23) may have problems using this AppImage. Please consider building it from source with Qt >= 5.14.

## Features

- Support Windows, Linux, and macOS.
- Support both Shadowsocks (without plugins) and V2Ray servers.
- Support connecting to multiple servers.
- Support adding/updating servers from subscription URLs.
- Support adding servers by importing [Shadowsocks-Qt5](https://github.com/shadowsocks/shadowsocks-qt5/) and [V2Ray Core](http://v2ray.com/) config.
- Support adding servers by scanning QR codes.
- Support PAC proxy mode, Global proxy mode, and Manual proxy mode.
- Support getting and setting system proxies for Windows, Linux (GNOME), and macOS.
- Support automatically updating GFWList.
- Support automatically starts up when logged in.

## Screenshot

<img width="1072" alt="Dashboard" src="https://user-images.githubusercontent.com/17879520/73626391-acae8500-4683-11ea-952f-b14dae450e0b.png">

<img width="1072" alt="Servers" src="https://user-images.githubusercontent.com/17879520/74507718-34c04480-4f38-11ea-89a3-8f2faea5ec0b.png">

## License

This project is licensed under version 3 of the GNU General Public License.
