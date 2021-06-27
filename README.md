# C++ lections

## How to build

### Prerequisites

You must have installed on your machine:

- python 3.7 or greater
- docker

### Installing dogebuild

This project uses [dogebuild](https://github.com/dogebuild/dogebuild) builder with [dogebuild-tex](https://github.com/dogebuild/dogebuild-tex) plugin.

To install required python modules you must call:

```sh
pip install -r requirements.txt 
```

### Build .pdf

To build pdf call:

```sh
doge build
```

Builded .pdf will be in `build` directory.
