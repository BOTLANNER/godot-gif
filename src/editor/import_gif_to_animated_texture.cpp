#include "gifmanager.h"
#include "image_frames.h"
#include "import_gif_to_animated_texture.h"

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

GifToAnimatedTextureImportPlugin::GifToAnimatedTextureImportPlugin()
{
    UtilityFunctions::print("Setting up GIF to ATEX Importer");
}

GifToAnimatedTextureImportPlugin::~GifToAnimatedTextureImportPlugin()
{
    UtilityFunctions::print("Tearing down GIF to ATEX Importer");
}

GifToAnimatedTexturePlugin::GifToAnimatedTexturePlugin()
{
}

GifToAnimatedTexturePlugin::~GifToAnimatedTexturePlugin()
{
}

void GifToAnimatedTexturePlugin::_enable_plugin()
{
    // Internal plugin, this doesn't seem to get called.
}

void GifToAnimatedTexturePlugin::_disable_plugin()
{
    // Internal plugin, this doesn't seem to get called.
}

void GifToAnimatedTexturePlugin::_ready()
{
    UtilityFunctions::print("GIF to ATEX Importer Ready");
}

void GifToAnimatedTexturePlugin::_enter_tree()
{
    UtilityFunctions::print("Setting up GIF to ATEX");
    gtatip.instantiate();
    add_import_plugin(gtatip);
}

void GifToAnimatedTexturePlugin::_exit_tree()
{
    UtilityFunctions::print("Tearing down GIF to ATEX");
    remove_import_plugin(gtatip);
    gtatip.unref();
}

String GifToAnimatedTexturePlugin::_get_plugin_name() const
{
    printf("GifToAnimatedTexturePlugin::_get_plugin_name");
    return "GIF to AnimatedTexture";
}

Ref<Texture2D> GifToAnimatedTexturePlugin::_get_plugin_icon() const
{
    printf("GifToAnimatedTexturePlugin::_get_plugin_icon");
    return memnew(Texture2D());
}

bool GifToAnimatedTexturePlugin::_has_main_screen() const
{
    printf("GifToAnimatedTexturePlugin::_has_main_screen");
    return false;
}

void GifToAnimatedTexturePlugin::_make_visible(bool visible)
{
    printf("GifToAnimatedTexturePlugin::_make_visible");
}

void GifToAnimatedTexturePlugin::_edit(Object *object)
{
    printf("GifToAnimatedTexturePlugin::_edit");
}

bool GifToAnimatedTexturePlugin::_handles(Object *object) const
{
    printf("GifToAnimatedTexturePlugin::_handles");
    return false;
}

void GifToAnimatedTexturePlugin::_bind_methods()
{
    // ClassDB::bind_method(D_METHOD("_enable_plugin"), &GifToAnimatedTexturePlugin::_enable_plugin);
    // ClassDB::bind_method(D_METHOD("_disable_plugin"), &GifToAnimatedTexturePlugin::_disable_plugin);
}

void GifToAnimatedTextureImportPlugin::_bind_methods()
{
    // ClassDB::bind_method(D_METHOD("_get_importer_name"), &GifToAnimatedTextureImportPlugin::_get_importer_name);
    // ClassDB::bind_method(D_METHOD("_get_visible_name"), &GifToAnimatedTextureImportPlugin::_get_visible_name);
    // ClassDB::bind_method(D_METHOD("_get_preset_count"), &GifToAnimatedTextureImportPlugin::_get_preset_count);
    // ClassDB::bind_method(D_METHOD("_get_preset_name", "preset_index"), &GifToAnimatedTextureImportPlugin::_get_preset_name, DEFVAL(0));
    // ClassDB::bind_method(D_METHOD("_get_recognized_extensions"), &GifToAnimatedTextureImportPlugin::_get_recognized_extensions);
    // ClassDB::bind_method(D_METHOD("_get_import_options", "path", "preset_index"), &GifToAnimatedTextureImportPlugin::_get_import_options, DEFVAL(0));
    // ClassDB::bind_method(D_METHOD("_get_save_extension"), &GifToAnimatedTextureImportPlugin::_get_save_extension);
    // ClassDB::bind_method(D_METHOD("_get_resource_type"), &GifToAnimatedTextureImportPlugin::_get_resource_type);
    // ClassDB::bind_method(D_METHOD("_get_option_visibility", "path", "option_name", "options"), &GifToAnimatedTextureImportPlugin::_get_option_visibility);
    // ClassDB::bind_method(D_METHOD("_import", "source_file", "save_path", "options", "platform_variants", "gen_files"), &GifToAnimatedTextureImportPlugin::_import);
}

String GifToAnimatedTextureImportPlugin::_get_importer_name() const
{
    return "import_gif_to_animated_texture";
}
String GifToAnimatedTextureImportPlugin::_get_visible_name() const
{
    return "GIF to AnimatedTexure";
}

int32_t GifToAnimatedTextureImportPlugin::_get_preset_count() const
{
    return COUNT;
}

String GifToAnimatedTextureImportPlugin::_get_preset_name(int32_t preset_index = 0) const
{
    switch (preset_index)
    {
    case Presets::DEFAULT:
    default:
        return "Default";
    }
}

PackedStringArray GifToAnimatedTextureImportPlugin::_get_recognized_extensions() const
{
    PackedStringArray result = PackedStringArray();
    result.push_back("gif");
    return result;
}

TypedArray<Dictionary> GifToAnimatedTextureImportPlugin::_get_import_options(const String &path, int32_t preset_index = 0) const
{
    UtilityFunctions::print("Setting up GIF to ATEX Importer options");
    // Dictionary option;
    // option["name"] = "frames_per_second";
    // option["default_value"] = 30;
    // option["hint_string"] = "Set the FPS rate for the playback";

    TypedArray<Dictionary> options;
    // options.push_back(option);
    return options;
}

String GifToAnimatedTextureImportPlugin::_get_save_extension() const
{
    return "tres";
}

String GifToAnimatedTextureImportPlugin::_get_resource_type() const
{
    return "AnimatedTexture";
}

double GifToAnimatedTextureImportPlugin::_get_priority() const
{
    return 1.0;
}

int32_t GifToAnimatedTextureImportPlugin::_get_import_order() const
{
    return IMPORT_ORDER_SCENE;
}

bool GifToAnimatedTextureImportPlugin::_get_option_visibility(const String &path, const StringName &option_name, const Dictionary &options) const
{
    return true;
}

Error GifToAnimatedTextureImportPlugin::_import(const String &source_file, const String &save_path, const Dictionary &options, const TypedArray<String> &platform_variants, const TypedArray<String> &gen_files) const
{
    UtilityFunctions::print("Running GIF to ATEX Importer");
    Ref<AnimatedTexture> at = GifManager::get_singleton()->animated_texture_from_file(source_file, 0);

    UtilityFunctions::print("GIF to ATEX Importer -> Created new AnimatedTexture");
    return ResourceSaver::get_singleton()->save(at, "" + save_path + "." + _get_save_extension(), 0);
}