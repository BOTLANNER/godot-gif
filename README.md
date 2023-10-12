# Godot GIF

## Description
GDExtension for Godot 4+ to load GIF files as [AnimatedTexture](https://docs.godotengine.org/en/stable/classes/class_animatedtexture.html) and/or [SpriteFrames](https://docs.godotengine.org/en/stable/classes/class_spriteframes.html).

NOTE: ~~**AnimatedTexture**~~ has been marked as deprecated according to development docs and could be removed in a future version of Godot.

## Contributing

### Setup

Ensure **SCons** is setup. Refer to [Introduction to the buildsystem](https://docs.godotengine.org/en/stable/contributing/development/compiling/introduction_to_the_buildsystem.html)

* If using a different version of Godot, be sure to dump the bindings e.g. 
    ```sh
        godot --dump-extension-api extension_api.json
    ```
*  Compile with 
    ```sh
        scons platform=<platform> custom_api_file=extension_api.json
    ```

### Debugging

This repository is configured for use with [VSCode](https://code.visualstudio.com/)

[Launch configurations](./.vscode/launch.json) have been setup for both debugging in editor and in runtime provided certain **VSCode** extensions are present and environment variables are defined.

The following environment variables are required:

1. `GODOT_PATH` - The directory in which Godot is installed
1. `GODOT_EXECUTABLE` - The executable name of the Godot installation

## More Details
Refer to [GDExtension C++ example](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html)


## License

Unless otherwise specified, the extension is released under the
[MIT license](LICENSE.txt).

See the full list of third-party libraries with their licenses used by this
extension at [src/thirdparty/README.md](src/thirdparty/README.md).

This implementation heavily borrowed inspiration from the [gif module](https://github.com/goostengine/goost/tree/gd3/modules/gif) for [Goost](https://github.com/goostengine/goost) that is currently only based on Godot 3
