# QML-Browser

QML-Browser. as the name suggests, is a browser for QML files like any other HTML(Web) Browser.

## Features

* Basic navigation: back, previous, reload
* JavaScript API like standard Web APIs

## Building

```sh
$ qmake
$ make
```

## Running

You need to serve QML files using any normal webserver. For example:

```
cd examples/google
python3 -m http.server
```

Run the `qml-browser` and type in the address bar: http://localhost:8000/main.qml

## JavaScript API

`window.back()`  [method]

The back method moves back one page in the history

`window.forward()` [method]

Moves forward one page in the session history

`window.location` [property]

This property sets or returns the entire URL of the current page

`window.title` [property]

This property sets or returns the title of the current page
