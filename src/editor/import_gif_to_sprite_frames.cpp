#include "gifmanager.h"
#include "image_frames.h"
#include "import_gif_to_sprite_frames.h"

#include "thirdparty/giflib/gif_lib.h"

#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/classes/sprite_frames.hpp>
#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/resource_saver.hpp>

#define godotgif_stringify(name) #name

using namespace godot;

GifToSpriteFramesImportPlugin::GifToSpriteFramesImportPlugin()
{
}

GifToSpriteFramesImportPlugin::~GifToSpriteFramesImportPlugin()
{
}

GifToSpriteFramesPlugin::GifToSpriteFramesPlugin()
{
}

GifToSpriteFramesPlugin::~GifToSpriteFramesPlugin()
{
}

void GifToSpriteFramesPlugin::_enable_plugin()
{
    // Internal plugin, this doesn't seem to get called.
}

void GifToSpriteFramesPlugin::_disable_plugin()
{
    // Internal plugin, this doesn't seem to get called.
}

void GifToSpriteFramesPlugin::_ready()
{
}

void GifToSpriteFramesPlugin::_enter_tree()
{
    gtatip.instantiate();
    add_import_plugin(gtatip);
}

void GifToSpriteFramesPlugin::_exit_tree()
{
    remove_import_plugin(gtatip);
    gtatip.unref();
}

String GifToSpriteFramesPlugin::_get_plugin_name() const
{
    return "GIF to SpriteFrames";
}

Ref<Texture2D> GifToSpriteFramesPlugin::_get_plugin_icon() const
{
    return memnew(Texture2D());
}

bool GifToSpriteFramesPlugin::_has_main_screen() const
{
    return false;
}

void GifToSpriteFramesPlugin::_make_visible(bool visible)
{
}

void GifToSpriteFramesPlugin::_edit(Object *object)
{
}

bool GifToSpriteFramesPlugin::_handles(Object *object) const
{
    return false;
}

void GifToSpriteFramesPlugin::_bind_methods()
{
    // ClassDB::bind_method(D_METHOD("_enable_plugin"), &GifToSpriteFramesPlugin::_enable_plugin);
    // ClassDB::bind_method(D_METHOD("_disable_plugin"), &GifToSpriteFramesPlugin::_disable_plugin);
}

void GifToSpriteFramesImportPlugin::_bind_methods()
{
    // ClassDB::bind_method(D_METHOD("_get_importer_name"), &GifToSpriteFramesImportPlugin::_get_importer_name);
    // ClassDB::bind_method(D_METHOD("_get_visible_name"), &GifToSpriteFramesImportPlugin::_get_visible_name);
    // ClassDB::bind_method(D_METHOD("_get_preset_count"), &GifToSpriteFramesImportPlugin::_get_preset_count);
    // ClassDB::bind_method(D_METHOD("_get_preset_name", "preset_index"), &GifToSpriteFramesImportPlugin::_get_preset_name, DEFVAL(0));
    // ClassDB::bind_method(D_METHOD("_get_recognized_extensions"), &GifToSpriteFramesImportPlugin::_get_recognized_extensions);
    // ClassDB::bind_method(D_METHOD("_get_import_options", "path", "preset_index"), &GifToSpriteFramesImportPlugin::_get_import_options, DEFVAL(0));
    // ClassDB::bind_method(D_METHOD("_get_save_extension"), &GifToSpriteFramesImportPlugin::_get_save_extension);
    // ClassDB::bind_method(D_METHOD("_get_resource_type"), &GifToSpriteFramesImportPlugin::_get_resource_type);
    // ClassDB::bind_method(D_METHOD("_get_option_visibility", "path", "option_name", "options"), &GifToSpriteFramesImportPlugin::_get_option_visibility);
    // ClassDB::bind_method(D_METHOD("_import", "source_file", "save_path", "options", "platform_variants", "gen_files"), &GifToSpriteFramesImportPlugin::_import);
}

String GifToSpriteFramesImportPlugin::_get_importer_name() const
{
    return "import_gif_to_sprite_frames";
}
String GifToSpriteFramesImportPlugin::_get_visible_name() const
{
    return "GIF to SpriteFrames";
}

int32_t GifToSpriteFramesImportPlugin::_get_preset_count() const
{
    return COUNT;
}

String GifToSpriteFramesImportPlugin::_get_preset_name(int32_t preset_index = 0) const
{
    switch (preset_index)
    {
    case Presets::DEFAULT:
    default:
        return "Default";
    }
}

PackedStringArray GifToSpriteFramesImportPlugin::_get_recognized_extensions() const
{
    PackedStringArray result = PackedStringArray();
    result.push_back("gif");
    return result;
}

TypedArray<Dictionary> GifToSpriteFramesImportPlugin::_get_import_options(const String &path, int32_t preset_index = 0) const
{
    Dictionary option;
    option["name"] = "frames_per_second";
    option["default_value"] = 30;
    option["hint_string"] = "Set the FPS rate for the playback";

    TypedArray<Dictionary> options;
    options.push_back(option);
    return options;
}

String GifToSpriteFramesImportPlugin::_get_save_extension() const
{
    return "tres";
}

String GifToSpriteFramesImportPlugin::_get_resource_type() const
{
    return "SpriteFrames";
}

float GifToSpriteFramesImportPlugin::_get_priority() const
{
    return 1.1;
}

int32_t GifToSpriteFramesImportPlugin::_get_import_order() const
{
    return IMPORT_ORDER_DEFAULT;
}

bool GifToSpriteFramesImportPlugin::_get_option_visibility(const String &path, const StringName &option_name, const Dictionary &options) const
{
    return true;
}

Error GifToSpriteFramesImportPlugin::_import(const String &source_file, const String &save_path, const Dictionary &options, const TypedArray<String> &platform_variants, const TypedArray<String> &gen_files) const
{
    UtilityFunctions::print("Running GIF to SpriteFrames Importer");
    double fps = 30;
    if (options.has("frames_per_second")) {
        fps = options["frames_per_second"];
    }
    Ref<SpriteFrames> sf = GifManager::get_singleton()->sprite_frames_from_file(source_file, 0, fps);
    return ResourceSaver::get_singleton()->save(sf, "" + save_path + "." + _get_save_extension(), 0);
}
