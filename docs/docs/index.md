# What is QML Browser?

QML-Browser, as the name suggests, is a browser for QML files like any other HTML(Web) Browser.

## Why?

Currently, the web is built in HTML, CSS & JavaScript. And that's great, but there are other language that deserve more attention: QML

## What is QML?

QML it is a declarative markup language (like HTML) but instead of being based on XML, it's closer to JSON and supports Javascript for scripting. It can perform everything HTML/CSS can and even more.

## QML vs HTML

Recently, I came across a few articles [1, 2, 3] comparing Qt's modern UI framework - Qt Quick and its own declarative language QML to HTML, with QML coming out as a clear winner in several categories:

* Speed of learning
* Ease of use
* Performance
* Cross-platform compatibility

# Features

* Basic navigation: back, previous, reload
* JavaScript API like standard Web APIs

## Installing

### From source

```sh
$ qmake
$ make
```

### Binary

- :computer: [Windows](https://github.com/gustavosbarreto/qml-browser/releases/download/continuous/qml-browser_release.zip)
- :apple: [MacOS](https://github.com/gustavosbarreto/qml-browser/releases/download/continuous/qml-browser.dmg)
- :penguin: [Linux](https://github.com/gustavosbarreto/qml-browser/releases/download/continuous/qml-browser.AppImage)

## Running

You need to serve QML files using any normal webserver. For example:

```
cd examples/google
python3 -m http.server
```

Run the `qml-browser` and type in the address bar: http://localhost:8000/main.qml

## JavaScript API

### Navigation

`window.back()`  [method]

The back method moves back one page in the history

`window.forward()` [method]

Moves forward one page in the session history

`window.location` [property]

This property sets or returns the entire URL of the current page

### Window

`window.title` [property]

### Dialog

This property sets or returns the title of the current page

`window.alert(message)` [method]

Displays an alert dialog with th specified message and an OK button.

`window.prompt(message, value)` [method]

Returns the text entered by the user in a prompt dialog.

`window.confirm(message)` [method]

Displays a dialog with a message that the user needs to respond to.

## QML module

The QmlBrowser module provides QML types similar to basic Web Elements like links (HTML a tag).

The QML types can be imported into your application using the following import statement in your .qml file.

`import QmlBrowser 1.0`

### LinkArea

Identical to `MouseArea`, but with `href` property and a default handler for mouse clicks.

Example:

```qml
LinkArea {
  anchors.fill: parent
  href: "http://localhost:8000/page2.qml"
}
```

### TextLink

Identical to `Text`, but with `href` property and a `LinkArea` inside.

Example:

```qml
TextLink {
  text: "Link to page2.qml"
  href: "http://localhost:8000/page2.qml"
}
```
