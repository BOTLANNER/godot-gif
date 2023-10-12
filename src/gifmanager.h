#ifndef GODOT_GIFMANAGER_H
#define GODOT_GIFMANAGER_H

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

#include "thirdparty/giflib/gif_lib.h"

using namespace godot;

class GifManager : public Object
{

    GDCLASS(GifManager, Object);
    static GifManager *singleton;
    GifFileType *gif;

public:
    static GifManager *get_singleton();
    GifManager();
    ~GifManager();

    Ref<AnimatedTexture> animated_texture_from_file(const String &path, int max_frames);
    Ref<AnimatedTexture> animated_texture_from_buffer(const PackedByteArray &p_data, int max_frames);
    Ref<SpriteFrames> sprite_frames_from_file(const String &path, int max_frames);
    Ref<SpriteFrames> sprite_frames_from_buffer(const PackedByteArray &p_data, int max_frames);

protected:
    static void _bind_methods();

private:
    Ref<AnimatedTexture> i_f_to_a_t(const Ref<ImageFrames> &frames);
    Ref<SpriteFrames> i_f_to_s_f(const Ref<ImageFrames> &frames);
};

#endif // GODOT_GIFMANAGER_H