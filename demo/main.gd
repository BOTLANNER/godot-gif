@tool
extends Node

func _ready():
	print("Hello")
	if Engine.is_editor_hint():
		print("Hello Editor")
		var file = FileAccess.get_file_as_bytes("res://examples/file/optic.gif")
		var tex = GifManager.animated_texture_from_buffer(file)
		var frms = GifManager.sprite_frames_from_buffer(file)
		print(tex)
		ResourceSaver.save(tex,"examples/file/optic_a.tres")
		ResourceSaver.save(frms,"examples/file/optic_s.tres")
	else:
		print("Hello Game")
		$AnimFromSaved.texture = load("res://examples/file/optic_a.tres")
		$AnimatedSprite2D.sprite_frames = load("res://examples/file/optic_s.tres")
		#$AnimatedSprite2D.autoplay = "gif"
		$AnimatedSprite2D.play("gif")
		
		$AnimFromRuntimeFile.texture = GifManager.animated_texture_from_file("res://examples/file/optic.gif")
		$AnimatedSprite2RuntimeFile.sprite_frames = GifManager.sprite_frames_from_file("res://examples/file/optic.gif")
		#$AnimatedSprite2RuntimeFile.autoplay = "gif"
		$AnimatedSprite2RuntimeFile.play("gif")
		
		# Create an HTTP request node and connect its completion signal.
		var http_request = HTTPRequest.new()
		add_child(http_request)
		var error = http_request.request("https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExdTBjNGVoNWVmbmppMmNiajB4MGp5c2lhbTN2a3I4b2pwZnhweW45cyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/cNvyHFALpPHomfxQy0/giphy.gif")
		if error != OK:
			push_error("An error occurred in the HTTP request.")
		else:
			var results = await http_request.request_completed
			var result = results[0]
			var response_code = results[1]
			var headers = results[2]
			var body = results[3]
			print(result)
			print(response_code)
			if result == OK && response_code == 200:
				var tex = GifManager.animated_texture_from_buffer(body)
				if tex != null:
					$AnimFromRuntime.texture = tex
				var frms = GifManager.sprite_frames_from_buffer(body)
				if frms != null:
					$AnimatedSprite2DFromRuntime.sprite_frames = frms
					#$AnimatedSprite2DFromRuntime.autoplay = "gif"
					$AnimatedSprite2DFromRuntime.play("gif")
				
		http_request.queue_free()
