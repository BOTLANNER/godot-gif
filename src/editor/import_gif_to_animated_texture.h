#ifndef GODOT_GIF_IMPORT_AT_H
#define GODOT_GIF_IMPORT_AT_H

#include "image_frames.h"

// Include Godot headers
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/dictionary.hpp>

#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/classes/animated_texture.hpp>
#include <godot_cpp/classes/sprite_frames.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/classes/editor_import_plugin.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>

#include "thirdparty/giflib/gif_lib.h"

using namespace godot;

class GifToAnimatedTextureImportPlugin : public EditorImportPlugin
{

    GDCLASS(GifToAnimatedTextureImportPlugin, EditorImportPlugin);

public:
    enum Presets
    {
        DEFAULT,
        COUNT
    };

    GifToAnimatedTextureImportPlugin();
    ~GifToAnimatedTextureImportPlugin();

    String _get_importer_name() const;
    String _get_visible_name() const;
    int32_t _get_preset_count() const;
    String _get_preset_name(int32_t preset_index) const;
    PackedStringArray _get_recognized_extensions() const;
    TypedArray<Dictionary> _get_import_options(const String &path, int32_t preset_index) const;
    String _get_save_extension() const;
    String _get_resource_type() const;
	float _get_priority() const;
	int32_t _get_import_order() const;
    bool _get_option_visibility(const String &path, const StringName &option_name, const Dictionary &options) const;
    Error _import(const String &source_file, const String &save_path, const Dictionary &options, const TypedArray<String> &platform_variants, const TypedArray<String> &gen_files) const;

protected:
    static void _bind_methods();

private:
};

class GifToAnimatedTexturePlugin : public EditorPlugin
{
    GDCLASS(GifToAnimatedTexturePlugin, EditorPlugin);

    Ref<GifToAnimatedTextureImportPlugin> gtatip;

public:
    GifToAnimatedTexturePlugin();
    ~GifToAnimatedTexturePlugin();
	void _enable_plugin();
	void _disable_plugin();
    
	String _get_plugin_name() const;
	Ref<Texture2D> _get_plugin_icon() const;
	bool _has_main_screen() const;
	void _make_visible(bool visible);
	void _edit(Object *object);
	bool _handles(Object *object) const;
	void _enter_tree();
	void _exit_tree();
	void _ready();

protected:
    static void _bind_methods();
};

VARIANT_ENUM_CAST(GifToAnimatedTextureImportPlugin::Presets);

#endif // GODOT_GIF_IMPORT_AT_H
