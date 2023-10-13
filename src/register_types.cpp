#include "register_types.h"

#include "import_gif_to_animated_texture.h"
#include "import_gif_to_sprite_frames.h"
#include "gifmanager.h"
#include "image_frames.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

static GifManager *GifMngrPtr;

void register_gif_types(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		ClassDB::register_class<ImageFrames>();
		ClassDB::register_class<GifManager>();
		GifMngrPtr = memnew(GifManager);
		Engine::get_singleton()->register_singleton("GifManager", GifManager::get_singleton());
	}

	if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR)
	{

		ClassDB::register_class<GifToSpriteFramesImportPlugin>();
		ClassDB::register_class<GifToSpriteFramesPlugin>();
		EditorPlugins::add_by_type<GifToSpriteFramesPlugin>();

		ClassDB::register_class<GifToAnimatedTextureImportPlugin>();
		ClassDB::register_class<GifToAnimatedTexturePlugin>();
		EditorPlugins::add_by_type<GifToAnimatedTexturePlugin>();
	}
}

void unregister_gif_types(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		Engine::get_singleton()->unregister_singleton("GifManager");
		memdelete(GifMngrPtr);
	}

	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		EditorPlugins::remove_by_type<GifToSpriteFramesPlugin>();
		EditorPlugins::remove_by_type<GifToAnimatedTexturePlugin>();
	}
}

extern "C"
{
	// Initialization.
	GDExtensionBool GDE_EXPORT godot_gif_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(register_gif_types);
		init_obj.register_terminator(unregister_gif_types);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}