#include "register_types.h"

#include "gifmanager.h"
#include "image_frames.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

static GifManager *GifMngrPtr;


void register_gif_types(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		return;
	}
	ClassDB::register_class<ImageFrames>();
	ClassDB::register_class<GifManager>();
	GifMngrPtr = memnew(GifManager);
	Engine::get_singleton()->register_singleton("GifManager", GifManager::get_singleton());
}

void unregister_gif_types(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		return;
	}
	Engine::get_singleton()->unregister_singleton("GifManager");
	memdelete(GifMngrPtr);
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